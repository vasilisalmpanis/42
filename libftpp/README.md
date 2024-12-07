
DataBuffer -> Polymorphic container to store objects in form byte format. Serializarion, deserialization, template specialization.

# Mandatory
1. **General structure of the library**
    - Provides a unified header file named libftpp.hpp
    - Includes all the necessary headers from the toolbox

2. **Data Structure**
    - [Pool and Pool::Object](#Pool)
    - [DataBuffer]()

3. **Design Pattern**
    - [Memento]()
    - [Observer]()
    - [Singleton]()
    - [StateMachine]()

4. **IOStream**
    - [ThreadSafeIOStream]()

5. **Thread**
    - [ThreadSafeIOStream]()
    - [Thread]()
    - [WorkerPool]()
    - [PersistentWorker]()

6. **Networ**
    - [Message]()
    - [Client]()
    - [Server]()

7. **Mathematic**
    - [IVector2]()
    - [IVector3]()
    - [Random2DCoordinateGenerator]()
    - [PerlinNoise2D]()

# Bonus
` // TODO `

# Pool
Resource management class that takes care of preallocating objects andreturning  
returning pointers. Acts like smart_pointer class (unique ptr)
