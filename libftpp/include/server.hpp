#pragma once
#include <algorithm>
#include <atomic>
#include <message.hpp>
#include <sys/select.h>

/* 1. we need io multiplexer
 * 2. keeps client file descriptors by id (global id that increments when client
 * connects
 * 3. each client needs to save the messages received by them to be processed by
 * update()
 */

/*
 * step 1. getaddrinfo, socket, bind, listen and set socket to server socket.
 * step 2. start a background thread that polls for new events, accepts
 * connections step 3. if it is a new connection accept, add a client and
 * continue step 4. if it is an already existing connection receive a message
 * and append it to the queue step 5. on update go through all clients and pop
 * each queue's message and call the respective action
 */

class Server {
public:
    Server();
    Server(Server &&) = delete;
    Server &operator=(Server &&) = delete;
    Server(const Server &);
    Server &operator=(const Server &);
    ~Server();

public:
    void defineAction(const Message::Type &messageType,
                      const std::function<void(long long &clientID,
                                               const Message &msg)> &action);
    void start(const size_t &p_port); // Start the server at the specified port.
    /* void sendTo(const Message &message, */
    /*             long long clientID); // Send a message to a specific client
     * ID. */
    /* void sendToArray( */
    /*     const Message &message, */
    /*     std::vector<long long> */
    /*         clientIDs); // Send a message to a specific set of client IDs. */
    /* void sendToAll(const Message &message); // Send a message to all clients
     */
    /*                                         // currently connected to the
     * server */
    /* void update(); /1* Process all received messages since last update */
    /*                 * call and execute the action subscribed by the user for
     */
    /*                 * each message. */
    /*                 *1/ */

private:
    void backgroundWork();

private:
    int _fd;
    std::vector<long long> _clients;
    std::unordered_map<Message::Type, std::function<void(const Message &)>>
        _actions;
    fd_set _master, _read_fds;
    std::thread _thread;
    std::mutex _mutex;
    std::atomic_bool _running;
};
