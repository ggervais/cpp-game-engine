/* 
 * File:   optional.hpp
 * Author: Guillaume
 *
 * Created on January 30, 2012, 8:58 PM
 * 
 * This optional class system is based on the model present by Mike McShaffry
 * in Game Coding Complete, Third Edition.
 * 
 * http://www.amazon.com/Game-Coding-Complete-Third-McShaffry/dp/1584506806
 * */

#ifndef OPTIONAL_HPP
#define	OPTIONAL_HPP

#include <assert.h>

// Empty class
class optional_empty {};

template<unsigned long size>
class optional_base {
public:
    // A optional variable always has a value of false by default.
    optional_base() : isValid(false) {}
    optional_base& operator=(optional_base const & t);
    optional_base(optional_base const & other) : isValid(other.isValid) {}
    
    bool const valid() { return isValid; }
    bool const invalid() { return !isValid; }
    
protected:
    bool isValid;
    char data[size];
};

template<class T>
class optional : public optional_base<sizeof(T)> {
public:
    optional() {}
    
    optional(T const & t) {
        construct(t);
        this->isValid = true;
    }
    
    optional(optional_empty &) {}
    
    
    optional& operator=(T const & t) {
        if (this->isValid) {
            *GetT() = t;
        } else {
            construct(t);
            this->isValid = true;
        }
    }
    
    optional(optional const & other) {
        if (other.isValid) {
            construct(*other);
            this->isValid = true;
        }
    }
    
    optional& operator=(optional const & other) {
        assert(!(this == &other));
        if (!this->isValid) {
            this->isValid = false;
            destroy();
        }
        
        if (other.isValid) {
            construct(*other);
            this->isValid = true;
        }
        
        return *this;
    }
    
    
    bool const operator==(optional const & other) const {
        if (!valid() && !other.valid()) {
            return true;
        }
        
        if (valid() ^ other.valid()) {
            return false;
        }
        
        return ((**this) == (*other));
    }
    
    
    bool const operator<(optional const & other) const {
        if (!valid() && !other.valid()) {
            return false;
        }
        
        if (!valid()) {
            return true;
        }
        
        if (!other.valid()) {
            return false;
        }
        
        return ((**this) < (*other));
    }
    
    ~optional() {
        if (this->isValid) {
            this->destroy();
        }
    }
    
    T const &operator*() const {
        assert(this->isValid);
        return *GetT();
    }
    
    T &operator*() {
        assert(this->isValid);
        return *GetT();
    }
    
    T const * const operator->() const {
        assert(this->isValid);
        return GetT();
    }
    
    T * const operator->() {
        assert(this->isValid);
        return GetT();
    }
    
    void clear() {
        if (this->isValid) {
            this->isValid = false;
            destroy();
        }
    }
   
    bool const valid() { return this->isValid; }
    bool const invalid() { return !this->isValid; }
    
private:
    T const * const GetT() const {
        return reinterpret_cast<T const * const>(this->data);
    }
    
    T * const GetT() {
        return reinterpret_cast<T * const>(this->data);
    }
    
    void construct(T const &t) {
        new (GetT()) T(t);
    }
    
    void destroy() {
        GetT()->~T();
    }
};



#endif	/* OPTIONAL_HPP */

