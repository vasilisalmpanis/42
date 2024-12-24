
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
    - [ThreadSafeQueue]()
    - [Thread]()
    - [WorkerPool]()
    - [PersistentWorker](#PersistentWorker)

6. **Network**
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
Resource management class that takes care of pre allocating objects and returning  
returning pointers. Acts like smart_pointer class (unique ptr)

# ThreadSafeIOStream
Uses mutexes and thread_local variables to preform thread-safe I/O with prefixed lines.  
Helps debug and monitor applications with multiple threads more easily.

- `Operator overloads for «, »`
- `void setPrefix(const std::string& prefix)`
- `template<typename T> void prompt(const std::string& question, T& dest)`

# PersistentWorker
A thread that continuously performs a set of tasks defined by  
users. It should maintain a list of tasks to perform in a loop.

- `void addTask(const std::string& name, const std::function<void()>& jobToExecute)`
- `void removeTask(const std::string& name)`

# Message
Handles messages between client and server
- `Message(int type):`
- `Templated operator overloads for «, »`
- `int type()`

# Client
# Server
