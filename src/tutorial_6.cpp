// file that contains the custom nodes definitions
#include "BT_example/tutorial_6.h"

#include "behaviortree_cpp_v3/loggers/bt_cout_logger.h"
#include "behaviortree_cpp_v3/loggers/bt_minitrace_logger.h"
#include "behaviortree_cpp_v3/loggers/bt_file_logger.h"
#include "behaviortree_cpp_v3/bt_factory.h"

/** This is a more complex example that uses Fallback,
 * Decorators and Subtrees
 *
 * For the sake of simplicity, we aren't focusing on ports remapping to the time being.
 *
 * Furthermore, we introduce Loggers, which are a mechanism to
 * trace the state transitions in the tree for debugging purposes.
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
