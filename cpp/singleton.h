template <typename T>
class singleton {
public:
    static T* get() {
        static T t;
        return &t;
    }

private:
    singleton() = delete;
    ~singleton() = delete;
    singleton(const singleton&) = delete;
    singleton &operator= (const singleton &) = delete;
};
