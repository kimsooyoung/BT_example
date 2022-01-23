#pragma once

#include <behaviortree_cpp_v3/action_node.h>
// #include <behaviortree_cpp_v3/bt_factory.h>

using namespace BT;


// Action_A has a different constructor than the default one.
class Action_A: public SyncActionNode
{

public:
    // additional arguments passed to the constructor
    Action_A(const std::string& name, const NodeConfiguration& config,
             int arg1, double arg2, std::string arg3 ):
        SyncActionNode(name, config),
        _arg1(arg1),
        _arg2(arg2),
        _arg3(arg3) {}

    // this example doesn't require any port
    static PortsList providedPorts() { return {}; }

    // tick() can access the private members
    NodeStatus tick() override
    {
        std::cout << "Action_A: " << _arg1 << " / " << _arg2 << " / " << _arg3 << std::endl;
        return NodeStatus::SUCCESS;
    }

private:
    int _arg1;
    double _arg2;
    std::string _arg3;
};

class Action_B: public SyncActionNode
{

public:
    // The constructor looks as usual.
    Action_B(const std::string& name, const NodeConfiguration& config):
        SyncActionNode(name, config) {}

    // We want this method to be called ONCE and BEFORE the first tick()
    void init( int arg1, double arg2, const std::string& arg3 )
    {
        _arg1 = (arg1);
        _arg2 = (arg2);
        _arg3 = (arg3);
    }

    // this example doesn't require any port
    static PortsList providedPorts() { return {}; }

    // tick() can access the private members
    NodeStatus tick() override
    {
        std::cout << "Action_B: " << _arg1 << " / " << _arg2 << " / " << _arg3 << std::endl;
        return NodeStatus::SUCCESS;
    }

private:
    int _arg1;
    double _arg2;
    std::string _arg3;
};
