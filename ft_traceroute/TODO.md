1. check pid that it corresponds to our pid to discard messages
2. adds duration support for intermmediate routers that return type == 11
3. optionally compare sockaddr_in structs to print if route changed in between
4. optionally check for checksum to discard faulty messages
