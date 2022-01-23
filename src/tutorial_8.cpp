// file that contains the custom nodes definitions
#include "BT_example/tutorial_8.h"

#include "behaviortree_cpp_v3/bt_factory.h"

/*
 * Sometimes, it is convenient to pass additional (static) arguments to a Node.
 * If these parameters are known at compilation time or at deployment-time
 * and they don't change at run-time, input ports are probably overkill and cumbersome.
 *
 * This tutorial demonstrates two possible ways to initialize a custom node with
 * additional arguments.
 */

using namespace BT;

int main()
{
    using namespace BT;

    BehaviorTreeFactory factory;

    // A node builder is a functor that creates a std::unique_ptr<TreeNode>.
    // Using lambdas or std::bind, we can easily "inject" additional arguments.
    NodeBuilder builder_A = [](const std::string& name, const NodeConfiguration& config)
    {
        return std::make_unique<Action_A>( name, config, 42, 3.14, "hello world" );
    };

    factory.registerBuilder<Action_A>( "Action_A", builder_A);
    // The regitration of  Action_B is done as usual, but remember
    // that we still need to call Action_B::init()
    factory.registerNodeType<Action_B>( "Action_B" );

    auto tree = factory.createTreeFromFile("/home/kimsooyoung/bt_ros2_ws/src/BT_example/bt_xml/tutorial_8_tree.xml");
    
    // Iterate through all the nodes and call init() if it is an Action_B
    for( auto& node: tree.nodes )
    {
        // Not a typo: it is "=", not "=="
        if( auto action_B = dynamic_cast<Action_B*>( node.get() ))
        {
            action_B->init(69, 9.99, "interesting_value");
        }
    }

    tree.tickRoot();

    return 0;
}

/* Expected output:

Action_A: 42 / 3.14 / hello world
Action_B: 42 / 3.14 / hello world
*/