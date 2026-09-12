class Foo {
public:
    mutex m;
    condition_variable cv;
    int step = 1;

    Foo() {
        
    }

    void first(function<void()> printFirst) {
        printFirst();

        {
            lock_guard<mutex> lock(m);
            step = 2;
        }

        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lock(m);

        cv.wait(lock, [&] {
            return step == 2;
        });

        printSecond();

        step = 3;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lock(m);

        cv.wait(lock, [&] {
            return step == 3;
        });

        printThird();
    }
};