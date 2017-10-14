#include <iostream>
#include <memory>

using namespace std;

class I
{
public:
    virtual ~I() = 0;
    virtual void f() = 0;
    virtual I* clone() const = 0;
};

I::~I()
{
}



class Imp : public virtual I
{
public:
    virtual ~Imp(){}
    virtual void f() override{}
};

class I2 : public virtual I
{
public:
    virtual ~I2(){}
    virtual void h() = 0;
};

class I2Imp : public virtual I2, public Imp
{
public:
    virtual ~I2Imp(){}
    virtual I2Imp* clone() const override{ return new I2Imp(*this); }
    virtual void h() override{}
};

int main(int, char**) {
    cout << "Start" << endl;
    I2Imp c;
    c.f();
    cout << "End" << endl;
    return 0;
}

template<class T>class Comparable
{
public:
    virtual ~Comparable()=0;
    virtual bool equals(const T& other);
};

class Clonable
{
public:
    virtual ~Clonable(){};
    virtual Clonable* clone() const = 0;
};

/*template<class T>class ClonableTImp : public virtual ClonableT<T>
{
public:
    virtual ~ClonableTImp(){}
    virtual T* clone() const override;//{ return new T(static_cast<const T&>(*this)); }
//	virtual T* clone() const override{ return new T(static_cast<const T&>(*this)); }
};
*/
#define DECL_CLONE(T) T* clone() const override = 0;


class A : public virtual Clonable
{
public:
    DECL_CLONE(A)
};

#define DEF_CLONE(T,TImp) T* clone() const override final{ return new TImp(*this); }

class ABase : public virtual A
{
public:
};

class AImp : public ABase
{
public:
    DEF_CLONE(A,AImp)
};

class B : public virtual A
{
public:
    DECL_CLONE(B)
};

class BBase : public ABase, public virtual B
{
public:
};

class BImp : public BBase
{
public:
    DEF_CLONE(B,BImp)
};


void f()
{
//    unique_ptr<B> b = make_unique<B>();
//    unique_ptr<A> a = unique_ptr<A>(b->clone());
    A* a = new AImp();
    B* b = new BImp();
    a = b->clone();
//	a->equals(*b);
//	b->equals(*a);
}
