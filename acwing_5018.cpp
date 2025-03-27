#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct Client {
    int DN;
    unordered_map<int, int> Value;
};

// 预处理索引结构 - 记录每个键值对对应的客户端
struct IndexCache {
    // 记录键和值都匹配的客户端
    unordered_map<int, unordered_map<int, vector<int>>> equalIndex;  // key -> value -> client indices

    // 记录键匹配但值不匹配的客户端
    unordered_map<int, unordered_map<int, vector<int>>> notEqualIndex;  // key -> value -> client indices that don't match
};

int n, m;

// 手动解析表达式，避免使用正则表达式
struct Condition {
    int key;
    char op;  // ':' or '~'
    int value;
};

// 解析单个条件 (key:value) 或 (key~value)
Condition parseCondition(const string& expr, size_t& pos) {
    Condition cond;

    // 跳过左括号
    pos++;

    // 解析键
    string key;
    while (pos < expr.size() && isdigit(expr[pos])) {
        key += expr[pos++];
    }
    cond.key = stoi(key);

    // 解析操作符
    cond.op = expr[pos++];

    // 解析值
    string value;
    while (pos < expr.size() && isdigit(expr[pos])) {
        value += expr[pos++];
    }
    cond.value = stoi(value);

    // 跳过右括号
    pos++;

    return cond;
}

// 解析完整表达式
vector<Condition> parseExpression(const string& expr) {
    vector<Condition> conditions;

    // 跳过开头的 & 或 |
    size_t pos = (expr[0] == '&' || expr[0] == '|') ? 1 : 0;

    // 处理不带括号的简单表达式 (如 "1:2" 或 "3~4")
    if (pos == 0 && expr.find('(') == string::npos) {
        Condition cond;
        string key;
        size_t i = 0;

        // 解析键
        while (i < expr.size() && isdigit(expr[i])) {
            key += expr[i++];
        }

        if (i < expr.size() && (expr[i] == ':' || expr[i] == '~')) {
            cond.key = stoi(key);
            cond.op = expr[i++];

            // 解析值
            string value;
            while (i < expr.size() && isdigit(expr[i])) {
                value += expr[i++];
            }

            cond.value = stoi(value);
            conditions.push_back(cond);
        }
        return conditions;
    }
    while (pos < expr.size()) {
        if (expr[pos] == '(') {
            conditions.push_back(parseCondition(expr, pos));
        }
        else {
            pos++;
        }
    }
    return conditions;
}

// 构建索引
IndexCache buildIndex(const vector<Client>& clients) {
    IndexCache cache;

    for (int j = 0; j < clients.size(); j++) {
        const auto& client = clients[j];

        for (const auto& [key, value] : client.Value) {
            // 添加到相等索引
            cache.equalIndex[key][value].push_back(j);

            // 添加到不等索引
            for (int v = 1; v <= 500; v++) {
                if (v != value && v != 0) {
                    cache.notEqualIndex[key][v].push_back(j);
                }
            }
        }
    }

    return cache;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    vector<Client> client(n);

    for (int i = 0; i < n; i++) {
        cin >> client[i].DN;
        int tmp;
        cin >> tmp;
        int a, b;
        for (int j = 0; j < tmp; j++) {
            cin >> a >> b;
            client[i].Value[a] = b;
        }
    }

    // 预处理构建索引
    IndexCache cache = buildIndex(client);

    cin >> m;
    string str;

    for (int i = 0; i < m; i++) {
        cin >> str;
        unordered_set<int> resultSet;

        // 确定表达式类型
        char expressionType = ' ';
        if (str[0] == '&') expressionType = '&';
        else if (str[0] == '|') expressionType = '|';

        // 解析表达式
        vector<Condition> conditions = parseExpression(str);

        if (conditions.empty()) {
            cout << "\n";
            continue;
        }

        // 处理单个条件表达式 (没有&或|)
        if (expressionType == ' ' && conditions.size() == 1) {
            Condition& cond = conditions[0];

            if (cond.op == ':') {
                // 查找键值匹配的客户端
                if (cache.equalIndex.count(cond.key) && cache.equalIndex[cond.key].count(cond.value)) {
                    for (int idx : cache.equalIndex[cond.key][cond.value]) {
                        resultSet.insert(client[idx].DN);
                    }
                }
            }
            else if (cond.op == '~') {
                // 查找键匹配但值不匹配的客户端
                if (cache.notEqualIndex.count(cond.key) && cache.notEqualIndex[cond.key].count(cond.value)) {
                    for (int idx : cache.notEqualIndex[cond.key][cond.value]) {
                        resultSet.insert(client[idx].DN);
                    }
                }
            }
        }
        // 处理AND表达式
        else if (expressionType == '&') {
            vector<bool> matches(n, true);

            for (const auto& cond : conditions) {
                if (cond.op == ':') {
                    // 更新不匹配的客户端
                    for (int j = 0; j < n; j++) {
                        auto it = client[j].Value.find(cond.key);
                        if (it == client[j].Value.end() || it->second != cond.value) {
                            matches[j] = false;
                        }
                    }
                }
                else if (cond.op == '~') {
                    // 更新不匹配的客户端
                    for (int j = 0; j < n; j++) {
                        auto it = client[j].Value.find(cond.key);
                        if (it != client[j].Value.end() && (it->second == cond.value || it->second == 0)) {
                            matches[j] = false;
                        }
                    }
                }
            }

            // 收集所有匹配的客户端
            for (int j = 0; j < n; j++) {
                if (matches[j]) {
                    resultSet.insert(client[j].DN);
                }
            }
        }
        // 处理OR表达式
        else if (expressionType == '|') {
            for (const auto& cond : conditions) {
                if (cond.op == ':') {
                    // 收集匹配的客户端
                    for (int j = 0; j < n; j++) {
                        auto it = client[j].Value.find(cond.key);
                        if (it != client[j].Value.end() && it->second == cond.value) {
                            resultSet.insert(client[j].DN);
                        }
                    }
                }
                else if (cond.op == '~') {
                    // 收集匹配的客户端
                    for (int j = 0; j < n; j++) {
                        auto it = client[j].Value.find(cond.key);
                        if (it != client[j].Value.end() && it->second != cond.value && it->second != 0) {
                            resultSet.insert(client[j].DN);
                        }
                    }
                }
            }
        }

        // 输出结果
        if (resultSet.empty()) {
            cout << "\n";
        }
        else {
            vector<int> result(resultSet.begin(), resultSet.end());
            sort(result.begin(), result.end());

            for (size_t j = 0; j < result.size(); j++) {
                cout << result[j];
                if (j < result.size() - 1) cout << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}