#pragma once
#include <atomic>
class spinlock_mutex final {
private:
    std::atomic_flag flag = ATOMIC_FLAG_INIT;

public:
    template <typename WhileIdleFunc = void()>
    void lock(WhileIdleFunc idle_work = [] {}) {
        while (flag.test_and_set(std::memory_order_acquire)) {
            idle_work();
        }
    }

    void unlock() {
        flag.clear(std::memory_order_release);
    }

    spinlock_mutex() = default;
    spinlock_mutex(const spinlock_mutex &) = delete;
    spinlock_mutex &operator=(const spinlock_mutex &) = delete;
};