# Transition

# Usage

### 1. Include header
```cpp
#include "transition.hpp"
```

### 2. Create a _Transition_ object (here with a _float_)
```cpp
trn::Transition<float> zoom(1.0f);
```

### 3. Use the _Transition_ object as any object of your type
```cpp
float twoTimes(float f)
{
    return 2.0f * f;
}

// Use our object
float twoZoom = twoTimes(zoom);
```

## Change the value of the _Transistion_ object
```cpp
zoom = 30.0f;
```
When affecting a new value to the transition object, it justs update the target value.

## Ajust transition time
By default the transition takes 1sec to complete (taking into account the fact that sigmoid never strictly reaches 1).

The _setSpeed_ method allows you to speed the transition up by a specified factor.
```cpp
// Now the transition takes 0.5s
zoom.setSpeed(2.0f);
```

# Technical limitations
 - The transition type only supports types implementing `operator+`, `operator-` and `operator*(float, const T&)`. Where `T` is the transition's template argument.
 
 - The interpolation function is limited to a _sigmoid_
 
 ![sigm](https://wiki.analytica.com/images/b/be/SigmoidGraph.png)
 
 # Future work
 
  - [ ] Add support for custom interpolation functions
  - [ ] Add support for manual update
