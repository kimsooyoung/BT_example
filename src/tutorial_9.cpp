// file that contains the custom nodes definitions
#include "BT_example/tutorial_9.h"

#include "behaviortree_cpp_v3/bt_factory.h"

/**
 * In this tutorial, we demonstrate how to use the CoroActionNode, which
 * should be preferred over AsyncActionNode when the functions you
 * use are non-blocking.
 *
 */

using namespace BT;

int main()
{
    // Simple tree: a sequence of two asycnhronous actions,
    // but the second will be halted because of the timeout.

    BehaviorTreeFactory factory;
    factory.registerNodeType<MyAsyncAction>("MyAsyncAction");

    auto tree = factory.createTreeFromFile("/home/kimsooyoung/bt_ros2_ws/src/BT_example/bt_xml/tutorial_9_tree.xml");

    //---------------------------------------
    // keep executin tick until it returns etiher SUCCESS or FAILURE
    while( tree.tickRoot() == NodeStatus::RUNNING)
    {
        std::this_thread::sleep_for( Milliseconds(10) );
    }
    return 0;
}

/* Expected output:

action_A: Started. Send Request to server.
action_A: Waiting Reply...
action_A: Done. 'Waiting Reply' loop repeated 11 times
action_A: cleaning up after SUCCESS

action_B: Started. Send Request to server.
action_B: Waiting Reply...
action_B: Halted.
action_B: cleaning up after an halt()

*/


// action_A: Started. Send Request to server.
// action_A: Waiting Reply...
// action_A: Done. 'Waiting Reply' loop repeated 11 times
// action_A: cleaning up after SUCCESS

// action_B: Started. Send Request to server.
// action_B: Waiting Reply...
// action_B: Halted.
// action_B: cleaning up after an halt()

// action_A: Halted.
// action_A: cleaning up after an halt()

// action_B: Halted.
// action_B: cleaning up after an halt()