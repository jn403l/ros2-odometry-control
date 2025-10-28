#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

#include <chrono>

using namespace std::chrono_literals;

class SimplePublisher : public rclcpp::Node
{
public:
	// define a constructor with pub_ and timer_
	SimplePublisher() : Node("simple_publisher"), counter_(0)
	{
		pub_ = create_publisher<std_msgs::msg::String>("chatter", 10);
    // replace std::bind with lambda
		// timer_ = create_wall_timer(1s, std::bind(&SimplePublisher::timerCallback, this));
    timer_ = create_wall_timer(1s, [this]{ timerCallback(); });

		RCLCPP_INFO(get_logger(), "publishing at 1Hz");
	}

private:
	unsigned int counter_;
	rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub_;
	rclcpp::TimerBase::SharedPtr timer_;

	void timerCallback()
	{
		auto message = std_msgs::msg::String();
		message.data = "Hello ROS 2 - counter: " + std::to_string(counter_++);

		pub_->publish(message);
	}
	
};

int main(int argc, char* argv[])
{
	rclcpp::init(argc, argv);
	auto node = std::make_shared<SimplePublisher>();
	rclcpp::spin(node);
	rclcpp::shutdown();
	return 0;
}
