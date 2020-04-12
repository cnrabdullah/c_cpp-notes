#pragma once

template <typename T>
class SmartPtr {
public:
    explicit SmartPtr(T* pm) : mptr{ pm } {}
    SmartPtr() = default;

    SmartPtr(const SmartPtr&) = delete;
    SmartPtr& operator= (const SmartPtr&) = delete;
    //--------------------------------------------------------------------------------------------

    SmartPtr(SmartPtr&& other) : mptr{ other.mptr }
    {
        other.mptr = nullptr;
    }

    //--------------------------------------------------------------------------------------------
    SmartPtr& operator=(SmartPtr&& other)
    {
        reset(other.mptr);
        other.mptr = nullptr;
        return *this;
    }
    //--------------------------------------------------------------------------------------------
    SmartPtr& operator=(std::nullptr_t)
    {
        reset();
        return *this;
    }

    //--------------------------------------------------------------------------------------------

    ~SmartPtr()
    {
        if (mptr)
            delete mptr;
    }
    //--------------------------------------------------------------------------------------------
    void reset(T* ptr = nullptr)
    {
        if (mptr)
            delete mptr;
        mptr = ptr;
    }

    //--------------------------------------------------------------------------------------------

    T* get()const
    {
        return mptr;
    }

    //--------------------------------------------------------------------------------------------

    T* release()
    {
        T* ptemp = mptr;
        mptr = nullptr;
        return ptemp;
    }

    //--------------------------------------------------------------------------------------------
    T& operator*()
    {
        return *mptr;
    }
    //--------------------------------------------------------------------------------------------

    T* operator->()
    {
        return mptr;
    }

private:
    T* mptr{ nullptr };
};

