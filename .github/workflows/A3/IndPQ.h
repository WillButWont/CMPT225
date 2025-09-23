/*
 * Name: William The
 * Student ID: 301586358
 * Login ID: wta57
 * Copyright: William The, 2025
 * Assignment: Assignment 3 Part A
 * Purpose: To implement an indexed priority queue using a heap and a hash map to efficiently support priority updates.
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stdexcept>

class IndPQ {
private:
    class Heap {
    public:
        std::vector<std::pair<int, std::string>> data; // stores (priority, taskID) pairs
        
        void swap(int i, int j, std::unordered_map<std::string, int> &M) {
            std::swap(data[i], data[j]); // swap elements in the heap
            M[data[i].second] = i; // update index mapping in M
            M[data[j].second] = j;
        }

        void percolate_up(int index, std::unordered_map<std::string, int> &M) {
            while (index > 0) {
                int parent = (index - 1) / 2; // find parent index
                if (data[index].first >= data[parent].first) break; // stop if heap property holds
                swap(index, parent, M); // swap with parent if needed
                index = parent; // move up
            }
        }

        void percolate_down(int index, std::unordered_map<std::string, int> &M) {
            int size = data.size();
            while (2 * index + 1 < size) { // while left child exists
                int left = 2 * index + 1;
                int right = 2 * index + 2;
                int smallest = left;
                if (right < size && data[right].first < data[left].first) // find smallest child
                    smallest = right;
                if (data[index].first <= data[smallest].first) break; // stop if heap property holds
                swap(index, smallest, M); // swap with smallest child
                index = smallest; // move down
            }
        }

        void insert(const std::string &taskid, int priority, std::unordered_map<std::string, int> &M) {
            data.emplace_back(priority, taskid); // add new task at the end
            int index = data.size() - 1; // get its index
            M[taskid] = index; // store index in M
            percolate_up(index, M); // maintain heap order
        }

        std::string deleteMin(std::unordered_map<std::string, int> &M) {
            if (data.empty()) throw std::runtime_error("Priority queue is empty");
            std::string minTask = data[0].second; // get min task
            M.erase(minTask); // remove from map
            if (data.size() > 1) {
                swap(0, data.size() - 1, M); // move last to root
            }
            data.pop_back(); // remove last
            if (!data.empty()) {
                percolate_down(0, M); // maintain heap order
            }
            return minTask; // return removed task
        }

        std::string getMin() {
            if (data.empty()) throw std::runtime_error("Priority queue is empty");
            return data[0].second; // return task with highest priority
        }

        void update(int index, int newPriority, std::unordered_map<std::string, int> &M) {
            int oldPriority = data[index].first;
            data[index].first = newPriority; // update priority
            if (newPriority < oldPriority)
                percolate_up(index, M); // move up if priority improved
            else
                percolate_down(index, M); // move down if priority worsened
        }
    };

    Heap heap; // heap instance
    std::unordered_map<std::string, int> M; // map taskID to heap index

public:
    void insert(const std::string &taskid, int priority) {
        if (M.find(taskid) != M.end()) throw std::runtime_error("Task ID already exists");
        heap.insert(taskid, priority, M); // insert into heap
    }

    std::string deleteMin() {
        return heap.deleteMin(M); // remove and return min task
    }

    std::string getMin() {
        return heap.getMin(); // return min task without removing it
    }

    void updatePriority(const std::string &taskid, int newPriority) {
        if (M.find(taskid) == M.end()) throw std::runtime_error("Task ID not found");
        heap.update(M[taskid], newPriority, M); // update priority in heap
    }

    void remove(const std::string &taskid) {
        if (M.find(taskid) == M.end()) throw std::runtime_error("Task ID not found");
        updatePriority(taskid, -1); // move to top with highest priority
        deleteMin(); // remove it
    }

    bool isEmpty() {
        return heap.data.empty(); // check if heap is empty
    }

    int size() {
        return heap.data.size(); // return number of tasks
    }

    void clear() {
        heap.data.clear(); // clear heap
        M.clear(); // clear map
    }

    void display() {
        for (const auto &entry : heap.data) {
            std::cout << "(" << entry.second << ", " << entry.first << ") "; // print each task and priority
        }
        std::cout << std::endl;
    }

    void ddisplay() {
        std::cout << "Heap contents: ";
        display(); // show heap
        std::cout << "Map contents: ";
        for (const auto &pair : M) {
            std::cout << "(" << pair.first << " -> " << pair.second << ") "; // show map key-value pairs
        }
        std::cout << std::endl;
    }
};
