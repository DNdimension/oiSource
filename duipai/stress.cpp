#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

// 生成随机的合法括号序列 (RBS)
void generate_data(int& n, int& k, string& s) {
	n = (rand() % 40+ 1) * 2; // 长度 2 ~ 20
	k = rand() % (n / 2 + 1);  // k 在 0 ~ n/2 之间
	
	s = "";
	int open = 0, close = 0;
	for (int i = 0; i < n; ++i) {
		if (open == n / 2) { 
			s += ')'; 
			close++; 
		} else if (open == close) { 
			s += '('; 
			open++; 
		} else {
			if (rand() % 2 == 0) { 
				s += '('; 
				open++; 
			} else { 
				s += ')'; 
				close++; 
			}
		}
	}
}

int main() {
	// 随机种子初始化
	srand(time(0));
	
	cout << "start stress test.make sure you have exe files" << endl;
	
	for (int test_case = 1; ; ++test_case) {
		int n, k;
		string s;
		generate_data(n, k, s);
		
		// ================= 1. 生成输入数据 =================
		// 使用 freopen 将标准输出重定向到 in.txt
		freopen("in.txt", "w", stdout);
		cout << 1 << "\n" << n << " " << k << "\n" << s << "\n";
		// 必须关闭 stdout，否则数据可能会留在缓冲区，导致外部程序读不到！
		fclose(stdout); 
		
		// ================= 2. 运行外部程序 =================
		// 使用 system 调用编译好的 exe，进行输入输出重定向
		system("ans.exe < in.txt > ans.txt");
		system("my.exe < in.txt > my.txt");
		
		// ================= 3. 读取结果 =================
		// 这里用 ifstream 或 freopen 都可以，为了避免污染 cin，用 ifstream 更稳妥
		ifstream f_my("my.txt");
		ifstream f_ans("ans.txt");
		
		int my_res,ans_res;
		
		// 如果文件非空，读取答案
		if (!(f_my >> my_res)) my_res = -1;
		if (!(f_ans >> ans_res)) ans_res = -1;
		
		f_my.close();
		f_ans.close();
		
		// ================= 4. 比较答案 =================
		if (ans_res != my_res) {
			// 发现错误，由于 stdout 刚才被重定向且关闭了，这里用 cerr 输出到屏幕
			cerr << "========================================\n";
			cerr << "diff! case #" << test_case << "\n";
			cerr << "input:\n";
			cerr << "1\n" << n << " " << k << "\n" << s << "\n";
			cerr << "----------------------------------------\n";
			cerr << "ans: " << ans_res << "\n";
			cerr << "my: " << my_res << "\n";
			cerr << "========================================\n";
			break; // 抓到一个错就停止
		}
		
		// 每测试 1000 次，在屏幕提示一下 (cerr 专门用于输出到屏幕，不受 freopen 影响)
		if (test_case % 1000 == 0) {
			cerr << "tested " << test_case << " all passed...\n";
		}
	}
	return 0;
}
