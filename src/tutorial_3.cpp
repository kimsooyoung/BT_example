#include "behaviortree_cpp_v3/bt_factory.h"

// file that contains the custom nodes definitions
#include "BT_example/tutorial_3.h"


// static const char* xml_text = R"(

//  <root main_tree_to_execute = "MainTree" >
//      <BehaviorTree ID="MainTree">
//         <SequenceStar name="root">
//             <CalculateGoal   goal="{GoalPosition}" />
//             <PrintTarget     target="{GoalPosition}" />
//             <SetBlackboard   output_key="OtherGoal" value="-1;3" />
//             <PrintTarget     target="{OtherGoal}" />
//         </SequenceStar>
//      </BehaviorTree>
//  </root>
//  )";

int main()
{
    using namespace BT;

    BehaviorTreeFactory factory;
    factory.registerNodeType<CalculateGoal>("CalculateGoal");
    factory.registerNodeType<PrintTarget>("PrintTarget");

    // auto tree = factory.createTreeFromText(xml_text);
    // or
    auto tree = factory.createTreeFromFile("/home/kimsooyoung/bt_ros2_ws/src/BT_example/bt_xml/tutorial_3_tree.xml");
    tree.tickRoot();

/* Expected output:

    Target positions: [ 1.1, 2.3 ]
    Converting string: "-1;3"
    Target positions: [ -1.0, 3.0 ]
*/
    return 0;
}