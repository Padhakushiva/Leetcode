class Foo {
private:
    mutex mtx;
    condition_variable cv;
    int state;

public:
    Foo() {
        state = 1;
    }

    void first(function<void()> printFirst) {

        printFirst();

        unique_lock<mutex> lock(mtx);
        state = 2;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {

        unique_lock<mutex> lock(mtx);

        cv.wait(lock, [this] {
            return state == 2;
        });

        printSecond();

        state = 3;
        cv.notify_all();
    }

    void third(function<void()> printThird) {

        unique_lock<mutex> lock(mtx);

        cv.wait(lock, [this] {
            return state == 3;
        });

        printThird();
    }
};