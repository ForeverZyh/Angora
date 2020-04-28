use super::{shm_conds, forkcli, shm_branches};
use std::ops::DerefMut;

use std::sync::Once;

static START: Once = Once::new();

#[ctor]
fn fast_init() {
    START.call_once(|| {
        shm_branches::map_branch_counting_shm();
        forkcli::start_forkcli();
    });
}

#[no_mangle]
pub extern "C" fn __angora_trace_cmp(
    condition: u32,
    cmpid: u32,
    context: u32,
    arg1: u64,
    arg2: u64,

    grad1: i32,
    grad2: i32,

) -> u32 {
    let mut conds = shm_conds::SHM_CONDS.lock().expect("SHM mutex poisoned.");
    match conds.deref_mut() {
        &mut Some(ref mut c) => {
            if c.check_match(cmpid, context) {
                // return c.update_cmp(condition, arg1, arg2);
                return c.update_cmp_with_grad(condition, arg1, arg2, grad1, grad2);
            }
        }
        _ => {}
    }
    condition
}

#[no_mangle]
pub extern "C" fn __angora_trace_switch(cmpid: u32, context: u32, condition: u64) -> u64 {
    let mut conds = shm_conds::SHM_CONDS.lock().expect("SHM mutex poisoned.");
    match conds.deref_mut() {
        &mut Some(ref mut c) => {
            if c.check_match(cmpid, context) {
                return c.update_switch(condition);
            }
        }
        _ => {}
    }
    condition
}
