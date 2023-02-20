
#include <iostream>


template<typename T>
class vector {
public:
    explicit vector(size_t n){
        arr_ = new T[n];
        capacity_ = n;
    }

    vector(){
        arr_ = new T[1];
        capacity_ = 1;
    }

    [[nodiscard]] bool empty() const {
        return size_ == 0;
    }
    [[nodiscard]] size_t size() const {
        return size_;
    }
    [[nodiscard]] size_t capacity() const {
        return capacity_;
    }

    void push_back(const T &value) {
        if(size_ >= capacity_){
            addMemory();
        }
        arr_[size_++] = value;
    }

    void clear() {
        delete[] arr_;
        arr_ = new T[1];
        capacity_ = 1;
        size_ = 0;
    }

    T& operator[] (size_t idx) {
        return arr_[idx];
    }

    const T& operator[](size_t idx) const {
        return arr_[idx];
    }

    vector& operator=(vector&& other) noexcept {
        if (this != &other) {
            delete[] arr_;
            arr_ = other.arr_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            other.arr_ = nullptr;
            other.size_ = other.capacity_ = 0;
        }
        return *this;
    }

    ~vector() {
        delete[] arr_;
    }
private:
    T *arr_;
    size_t size_{};
    size_t capacity_{};

    void addMemory(){
        capacity_ *= 2;
        T* tmp = arr_;
        arr_ = new T[capacity_];
        for (size_t i = 0; i < size_; ++i) {
            arr_[i] = tmp[i];
        }
        delete[] tmp;
    }
};

