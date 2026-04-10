#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

// 简单的函数示例
int add(int a, int b) {
    return a + b;
}

// 测试函数
bool test_add() {
    std::cout << "测试 add 函数... ";
    bool passed = true;
    
    // 测试用例
    if (add(2, 3) != 5) {
        std::cout << "失败: 2 + 3 != 5" << std::endl;
        passed = false;
    }
    
    if (add(-1, 1) != 0) {
        std::cout << "失败: -1 + 1 != 0" << std::endl;
        passed = false;
    }
    
    if (add(0, 0) != 0) {
        std::cout << "失败: 0 + 0 != 0" << std::endl;
        passed = false;
    }
    
    if (add(100, 200) != 300) {
        std::cout << "失败: 100 + 200 != 300" << std::endl;
        passed = false;
    }
    
    if (passed) {
        std::cout << "通过!" << std::endl;
    }
    
    return passed;
}

// 字符串处理函数示例
std::string reverse_string(const std::string& str) {
    std::string reversed = str;
    std::reverse(reversed.begin(), reversed.end());
    return reversed;
}

bool test_reverse_string() {
    std::cout << "测试 reverse_string 函数... ";
    bool passed = true;
    
    if (reverse_string("hello") != "olleh") {
        std::cout << "失败: 'hello' 反转不正确" << std::endl;
        passed = false;
    }
    
    if (reverse_string("") != "") {
        std::cout << "失败: 空字符串反转不正确" << std::endl;
        passed = false;
    }
    
    if (reverse_string("a") != "a") {
        std::cout << "失败: 单字符字符串反转不正确" << std::endl;
        passed = false;
    }
    
    if (reverse_string("racecar") != "racecar") {
        std::cout << "失败: 回文字符串反转不正确" << std::endl;
        passed = false;
    }
    
    if (passed) {
        std::cout << "通过!" << std::endl;
    }
    
    return passed;
}

// 简单的类示例
class Calculator {
private:
    int memory = 0;
    
public:
    int get_memory() const { return memory; }
    void set_memory(int value) { memory = value; }
    
    int add_to_memory(int value) {
        memory += value;
        return memory;
    }
    
    int multiply(int a, int b) {
        return a * b;
    }
    
    static double divide(double a, double b) {
        if (b == 0) {
            throw std::runtime_error("除零错误");
        }
        return a / b;
    }
};

bool test_calculator() {
    std::cout << "测试 Calculator 类... ";
    bool passed = true;
    
    try {
        Calculator calc;
        
        // 测试基本运算
        if (calc.multiply(3, 4) != 12) {
            std::cout << "失败: 3 * 4 != 12" << std::endl;
            passed = false;
        }
        
        // 测试内存功能
        calc.set_memory(10);
        if (calc.get_memory() != 10) {
            std::cout << "失败: 内存值不是 10" << std::endl;
            passed = false;
        }
        
        calc.add_to_memory(5);
        if (calc.get_memory() != 15) {
            std::cout << "失败: 内存值不是 15" << std::endl;
            passed = false;
        }
        
        // 测试静态方法
        if (Calculator::divide(10, 2) != 5.0) {
            std::cout << "失败: 10 / 2 != 5" << std::endl;
            passed = false;
        }
        
        // 测试异常
        try {
            Calculator::divide(10, 0);
            std::cout << "失败: 没有抛出除零异常" << std::endl;
            passed = false;
        } catch (const std::runtime_error&) {
            // 正常情况
        }
        
    } catch (const std::exception& e) {
        std::cout << "异常: " << e.what() << std::endl;
        passed = false;
    }
    
    if (passed) {
        std::cout << "通过!" << std::endl;
    }
    
    return passed;
}

// 主程序
int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "CMake 演示程序 - 单元测试" << std::endl;
    std::cout << "========================================" << std::endl;
    
    int passed_tests = 0;
    int total_tests = 0;
    
    // 运行所有测试
    if (test_add()) passed_tests++;
    total_tests++;
    
    if (test_reverse_string()) passed_tests++;
    total_tests++;
    
    if (test_calculator()) passed_tests++;
    total_tests++;
    
    // 演示一些额外的功能
    std::cout << "\n额外功能演示:" << std::endl;
    std::cout << "5 + 7 = " << add(5, 7) << std::endl;
    std::cout << "反转 'CMake': " << reverse_string("CMake") << std::endl;
    
    Calculator calc;
    calc.set_memory(100);
    std::cout << "计算器内存: " << calc.get_memory() << std::endl;
    std::cout << "计算器 8 * 9 = " << calc.multiply(8, 9) << std::endl;
    
    std::cout << "\n========================================" << std::endl;
    std::cout << "测试结果: " << passed_tests << "/" << total_tests << " 通过" << std::endl;
    
    if (passed_tests == total_tests) {
        std::cout << "所有测试通过!" << std::endl;
        return 0;
    } else {
        std::cout << "有测试失败!" << std::endl;
        return 1;
    }
}
