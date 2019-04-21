# Transition

# Usage

### 1. Include header
```cpp
#include "transition.hpp"
```

### 2. Create a _Transition_ object

```cpp
trn::Transition<float> zoom(1.0f);
```

### 3. Update the transition
```cpp
// Here we update every 16ms
float dt(0.016f);
zoom.update(dt);
```

### 4. Use the _Transition_ object as a float
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

