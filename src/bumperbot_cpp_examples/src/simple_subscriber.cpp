// declare libraries
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

using std::placeholders::_1;

// define the class SimpleSubscriber
// define the default constructor
// create_subscription<>() to create sub_ object
// define the msgCallback()

class SimpleSubscriber : public rclcpp::Node {
public:
  SimpleSubscriber() : Node("simple_subscriber") {
    sub_ = create_subscription<std_msgs::msg::String>("chatter", 10, std::bind(&SimpleSubscriber::msgCallback, this, _1));
  }

private:
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_;

  void msgCallback(const std_msgs::msg::String &msg) {
    RCLCPP_INFO_STREAM(get_logger(), "I heard: " << msg.data.c_str());
  }
};

// in main()
// initialize rclpp
// define a new node
// spin() the node
// shutdown() the process after

int main(int argc, char* argv[]) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<SimpleSubscriber>();
  rclcpp::spin(node);
  rclcpp::shutdown();

  return 0;
}
