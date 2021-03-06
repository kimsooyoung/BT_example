#include "behaviortree_cpp_v3/bt_factory.h"

// file that contains the custom nodes definitions
#include "BT_example/tutorial_4.h"

int main()
{
    using namespace BT;

    BehaviorTreeFactory factory;
    factory.registerSimpleCondition("BatteryOK", std::bind(CheckBattery));
    factory.registerNodeType<MoveBaseAction>("MoveBase");
    factory.registerNodeType<SaySomething>("SaySomething");

    auto tree = factory.createTreeFromFile("/home/kimsooyoung/bt_ros2_ws/src/BT_example/bt_xml/tutorial_4_tree.xml");

    NodeStatus status = NodeStatus::SUCCESS;

    std::cout << "\n--- 1st executeTick() ---" << std::endl;
    status = tree.tickRoot();

    SleepMS(150);
    std::cout << "\n--- 2nd executeTick() ---" << std::endl;
    status = tree.tickRoot();

    SleepMS(150);
    std::cout << "\n--- 3rd executeTick() ---" << std::endl;
    status = tree.tickRoot();

    // SleepMS(150);
    // std::cout << "\n--- 4rd executeTick() ---" << std::endl;
    // status = tree.tickRoot();

    std::cout << std::endl;

    return 0;
}

// --- 1st executeTick() ---
// [ Battery: OK ]
// Robot says: mission started...
// Converting string: "1;2;3"
// [ MoveBase: STARTED ]. goal: x=1 y=2.0 theta=3.00

// --- 2nd executeTick() ---
// [ MoveBase: FINISHED ]

// --- 3rd executeTick() ---
// Robot says: mission completed!