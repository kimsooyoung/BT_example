// file that contains the custom nodes definitions
#include "BT_example/tutorial_6.h"

#include "behaviortree_cpp_v3/bt_factory.h"

/** In the CrossDoor example we did not exchange any information
 * between the Maintree and the DoorClosed subtree.
 *
 * If we tried to do that, we would have noticed that it can't be done, because
 * each of the tree/subtree has its own Blackboard, to avoid the problem of name
 * clashing in very large trees.
 *
 * But a SubTree can have its own input/output ports.
 * In practice, these ports are nothing more than "soft links" between the
 * ports inside the SubTree (called "internal") and those in the parent
 * Tree (called "external").
 *
 */
 
using namespace BT;

int main()
{
    BT::BehaviorTreeFactory factory;

    factory.registerNodeType<SaySomething>("SaySomething");
    factory.registerNodeType<MoveBaseAction>("MoveBase");

    auto tree = factory.createTreeFromFile("/home/kimsooyoung/bt_ros2_ws/src/BT_example/bt_xml/tutorial_6_tree.xml");

    NodeStatus status = NodeStatus::RUNNING;
    // Keep on ticking until you get either a SUCCESS or FAILURE state
    while( status == NodeStatus::RUNNING)
    {
        status = tree.tickRoot();
        SleepMS(1);   // optional sleep to avoid "busy loops"
    }

    // let's visualize some information about the current state of the blackboards.
    std::cout << "--------------" << std::endl;
    tree.blackboard_stack[0]->debugMessage();
    std::cout << "--------------" << std::endl;
    tree.blackboard_stack[1]->debugMessage();
    std::cout << "--------------" << std::endl;

    return 0;
}

/* Expected output:

    [ MoveBase: STARTED ]. goal: x=1 y=2.0 theta=3.00
    [ MoveBase: FINISHED ]
    Robot says: mission accomplished
    --------------
    move_result (std::string) -> full
    move_goal (Pose2D) -> full
    --------------
    output (std::string) -> remapped to parent [move_result]
    target (Pose2D) -> remapped to parent [move_goal]
    --------------
*/
