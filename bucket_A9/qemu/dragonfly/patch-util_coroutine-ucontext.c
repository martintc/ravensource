--- util/coroutine-ucontext.c.orig	2023-08-22 15:34:02 UTC
+++ util/coroutine-ucontext.c
@@ -225,7 +225,15 @@ Coroutine *qemu_coroutine_new(void)
                 2, arg.i[0], arg.i[1]);
 
     /* swapcontext() in, siglongjmp() back out */
-    if (!sigsetjmp(old_env, 0)) {
+    /* Save signal mask in this sigsetjmp, because makecontext on DragonFly
+     * leaves all signals blocked when entering the new context with
+     * swapcontext.
+     * Workaround this, by just having the signal mask restored by the
+     * siglongjmp that brings us back from qemu_coroutine_new().
+     * XXX Remove this workaround when the makecontext behaviour is fixed
+     *     on DragonFly.
+     */
+    if (!sigsetjmp(old_env, 1)) {
         start_switch_fiber_asan(COROUTINE_YIELD, &fake_stack_save, co->stack,
                                 co->stack_size);
         start_switch_fiber_tsan(&fake_stack_save,
