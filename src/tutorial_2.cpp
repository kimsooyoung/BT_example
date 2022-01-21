#include "behaviortree_cpp_v3/bt_factory.h"

// file that contains the custom nodes definitions
#include "BT_example/tutorial_2.h"


int main()
{
    using namespace BT;

    BehaviorTreeFactory factory;

    factory.registerNodeType<SaySomething>("SaySomething");
    factory.registerNodeType<ThinkWhatToSay>("ThinkWhatToSay");

    // SimpleActionNodes can not define their own method providedPorts().
    // We should pass a PortsList explicitly if we want the Action to 
    // be able to use getInput() or setOutput();
    PortsList say_something_ports = { InputPort<std::string>("message") };
    factory.registerSimpleAction("SaySomething2", SaySomethingSimple, 
                                 say_something_ports );

    auto tree = factory.createTreeFromFile("/home/kimsooyoung/bt_ros2_ws/src/BT_example/bt_xml/tutorial_2_tree.xml");

    tree.tickRoot();

    /*  Expected output:

        Robot says: start thinking...
        Robot says: The answer is 42
        Robot says: SaySomething2 works too...
        Robot says: The answer is 42
    */
    return 0;
}