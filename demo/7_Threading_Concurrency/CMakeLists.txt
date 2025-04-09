add_executable(thread_demo thread_demo.cpp)

add_executable(jthread_join jthread_join.cpp)

add_executable(jthread_token jthread_token.cpp)

add_executable(call_once call_once.cpp)

add_executable(call_once_singleton call_once_singleton.cpp)

add_executable(sleep_until sleep_until.cpp)

add_executable(yield yield.cpp)

add_executable(launch launch.cpp)

add_executable(deferred deferred.cpp)

add_executable(promise promise.cpp)

add_executable(without_mutex without_mutex.cpp)

add_executable(with_mutex with_mutex.cpp)

add_executable(with_guard with_guard.cpp)

add_executable(with_uniquelock with_uniquelock.cpp)

add_executable(with_sharedmutex with_sharedmutex.cpp)

add_executable(with_timedmutex with_timedmutex.cpp)

add_executable(with_recursivemutex with_recursivemutex.cpp)

add_executable(atomic atomic.cpp)

add_executable(latch latch.cpp)

add_executable(barrier barrier.cpp)

add_executable(osyncstream osyncstream.cpp)