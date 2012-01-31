
#include "RendererObject.hpp"

template<typename T>
RendererObject<T>::RendererObject() : value() {
    
}

template<typename T>
RendererObject<T>::RendererObject(const RendererObject<T>& orig) : value(orig.value){
    
}

template<typename T>
T RendererObject<T>::getValue() const {
    return this->value;
}

template<typename T>
void RendererObject<T>::setValue(T value) {
    this->value = value;
}