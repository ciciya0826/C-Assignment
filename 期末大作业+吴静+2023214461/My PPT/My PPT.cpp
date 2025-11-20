#include "head.h"
using namespace std;
//抽象类
class CGraph {
public:
    virtual ~CGraph() = default;
    virtual void ShowMsg() const = 0;
    virtual string GetType() const = 0;
};
//矩形类，继承CGraph
class CRect : public CGraph {
private:
    int x, y, width, height;
    string text;
    int* pRect;
public:
    //构造函数
    CRect(int x, int y, int width, int height, const string& text = "")
        : x(x), y(y), width(width), height(height), text(text) {
        pRect = new int[5];
        for (int i = 0; i < 5; ++i) {
            pRect[i] = i;
        }
    }
    //拷贝构造函数
    CRect(const CRect& other) : x(other.x), y(other.y), width(other.width), height(other.height), text(other.text) {
        this->pRect = other.pRect;
    }
    //深拷贝构造函数
    CRect(const CRect&& other) : x(move(other.x)), y(move(other.y)), width(move(other.width)), height(move(other.height)), text(move(other.text)) {
        this->pRect = new int[5];
        for (int i = 0; i < 5; ++i) {
            this->pRect[i] = other.pRect[i];
        }
    }
    //析构函数
    ~CRect()override {
        delete[] pRect;
    }
    //展示信息
    void ShowMsg() const override {
        cout << "矩形的坐标为(" << x << "," << y << "),宽为" << width << ",高为" << height;
        if (!text.empty()) {
            cout << ",文本:内容为\"" << text << "\"";
        }
        cout << endl;
    }
    //显示类型
    string GetType() const override {
        return "Rect";
    }
    //设置文本内容
    void SetText(const string& newText) {
        text = newText;
    }
    //获取文本内容
    string GetText() const {
        return text;
    }
    //定义拷贝赋值运算符函数
    CRect& operator=(const CRect& other) {
        if (this == &other) {
            return *this;
        }
        delete[] pRect;
        x = other.x;
        y = other.y;
        width = other.width;
        height = other.height;
        text = other.text;
        pRect = new int[other.width * other.height];  
        for (int i = 0; i < other.width * other.height; ++i) {
            pRect[i] = other.pRect[i];
        }
        return *this;
    }
};
//椭圆类，继承CGraph
class CEllipse : public CGraph {
private:
    int x, y, majorAxis, minorAxis;
    string text;
    int* pEllipse;
public:
    //构造函数
    CEllipse(int x, int y, int majorAxis, int minorAxis, const string& text = "")
        : x(x), y(y), majorAxis(majorAxis), minorAxis(minorAxis), text(text) {
        pEllipse = new int[5];
        for (int i = 0; i < 5; ++i) {
            pEllipse[i] = i;
        }
    }
    //拷贝构造函数
    CEllipse(const CEllipse& other) : x(other.x), y(other.y), majorAxis(other.majorAxis), minorAxis(other.minorAxis), text(other.text) {
        this->pEllipse = new int[5];
        for (int i = 0; i < 5; ++i) {
            this->pEllipse[i] = other.pEllipse[i];
        }
    }
    //深拷贝构造函数
    CEllipse(CEllipse&& other) noexcept : x(move(other.x)), y(move(other.y)), majorAxis(move(other.majorAxis)), minorAxis(move(other.minorAxis)), text(move(other.text)) {
        this->pEllipse = other.pEllipse;
        other.pEllipse = nullptr;
    }
    //析构函数
    ~CEllipse() override {
        delete[] pEllipse;
    }
    //展示信息
    void ShowMsg() const override {
        cout << "椭圆的坐标为(" << x << "," << y << "),半长轴为" << majorAxis << ",半短轴为" << minorAxis;
        if (!text.empty()) {
            cout << ",文本:内容为\"" << text << "\"";
        }
        cout << endl;
    }
    //显示类型
    string GetType() const override {
        return "Ellipse";
    }
    //设置文本内容
    void SetText(const string& newText) {
        text = newText;
    }
    //获取文本内容
    string GetText() const {
        return text;
    }
    //定义赋值运算符函数
    CEllipse& operator=(const CEllipse& other) {
        if (this == &other) {
            return *this;
        }
        x = other.x;
        y = other.y;
        majorAxis = other.majorAxis;
        minorAxis = other.minorAxis;
        text = other.text;
        delete[] pEllipse;
        pEllipse = new int[5];
        for (int i = 0; i < 5; ++i) {
            pEllipse[i] = other.pEllipse[i];
        }
        return *this;
    }
};
//三角形类，继承CGraph
class CTriangle : public CGraph {
private:
    int x1, y1, x2, y2, x3, y3;
    string text;
    int* pTriangle;
public:
    // 构造函数
    CTriangle(int x1, int y1, int x2, int y2, int x3, int y3, const string& text = "")
        : x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3), text(text) {
        pTriangle = new int[5];
        for (int i = 0; i < 5; ++i) {
            pTriangle[i] = i;
        }
    }
    // 拷贝构造函数
    CTriangle(const CTriangle& other) : x1(other.x1), y1(other.y1), x2(other.x2), y2(other.y2), x3(other.x3), y3(other.y3), text(other.text) {
        this->pTriangle = new int[5];
        for (int i = 0; i < 5; ++i) {
            this->pTriangle[i] = other.pTriangle[i];
        }
    }
    // 深拷贝构造函数
    CTriangle(CTriangle&& other) noexcept : x1(move(other.x1)), y1(move(other.y1)), x2(move(other.x2)), y2(move(other.y2)), x3(move(other.x3)), y3(move(other.y3)), text(move(other.text)) {
        this->pTriangle = other.pTriangle;
        other.pTriangle = nullptr;
    }
    // 析构函数
    ~CTriangle() override {
        delete[] pTriangle;
    }
    // 展示信息
    void ShowMsg() const override {
        cout << "三角形的第一个顶点坐标为(" << x1 << "," << y1 << "),第二个顶点坐标为(" << x2 << "," << y2 << "),第三个顶点的坐标为(" << x3 << "," << y3 << ")" << endl;
    }
    // 显示类型
    string GetType() const override {
        return "Triangle";
    }
    // 设置文本内容
    void SetText(const string& newText) {
        text = newText;
    }
    // 获取文本内容
    string GetText() const {
        return text;
    }
    CTriangle& operator=(const CTriangle& other) {
        if (this == &other) {
            return *this;
        }
        x1 = other.x1;
        y1 = other.y1;
        x2 = other.x2;
        y2 = other.y2;
        x3 = other.x3;
        y3 = other.y3;
        text = other.text;
        delete[] pTriangle;
        pTriangle = new int[5];
        for (int i = 0; i < 5; ++i) {
            pTriangle[i] = other.pTriangle[i];
        }
        return *this;
    }
};
//圆角矩形类，继承CRect和CEllipse
class CRoundRect : public CRect, public CEllipse {
private:
    int* pRoundRect;
public:
    //构造函数
    CRoundRect(int x, int y, int width, int height, int majorAxis, int minorAxis, const string& text = "")
        : CRect(x, y, width, height, text), CEllipse(x, y, majorAxis, minorAxis, text) {
        pRoundRect = new int[5];
        for (int i = 0; i < 5; ++i) {
            pRoundRect[i] = i;
        }
    }
    //拷贝构造函数
    CRoundRect(const CRoundRect& other)
        : CRect(other), CEllipse(other), pRoundRect(nullptr) {
        pRoundRect = new int[5];
        for (int i = 0; i < 5; ++i) {
            pRoundRect[i] = other.pRoundRect[i];
        }
    }
    //深拷贝构造函数
    CRoundRect(CRoundRect&& other) noexcept
        : CRect(std::move(other)), CEllipse(std::move(other)), pRoundRect(other.pRoundRect) {
        other.pRoundRect = nullptr;
    }
    //析构函数
    ~CRoundRect() override {
        delete[] pRoundRect;
    }
    //展示信息
    void ShowMsg() const override {
        CRect::ShowMsg();
        CEllipse::ShowMsg();
        cout << "这是一个圆角矩形" << endl;
    }
    //显示类型
    string GetType() const override {
        return "RoundRect";
    }
    //定义赋值运算符函数
    CRoundRect& operator=(const CRoundRect& other) {
        if (this == &other) {
            return *this;
        }
        CRect::operator=(other);
        CEllipse::operator=(other);
        delete[] pRoundRect;
        pRoundRect = new int[5];
        for (int i = 0; i < 5; ++i) {
            pRoundRect[i] = other.pRoundRect[i];
        }
        return *this;
    }
};
//类似PPT页的类
class CPPage {
    friend class CRect;
private:
    vector<CGraph*> pages;
    vector<CRect> rectArray;
    vector<CEllipse> ellipseArray;
    vector<CTriangle> triangleArray;
    vector<CRoundRect> roundRectArray;
    static int pagecount;
public:
    //构造函数
    CPPage() {
        pagecount++;
    }
    //析构函数
    ~CPPage() {
        for (auto shape : pages) {
            delete shape;
        }
        pagecount--;
    }
    //返回页数
    static int GetPageCount() {
        return pagecount;
    }
    //添加图形
    void AddObject(CGraph* object) {
        pages.push_back(object);
        if (object->GetType() == "Rect") {
            CRect* rect = dynamic_cast<CRect*>(object);
            if (rect) {
                rectArray.push_back(*rect);
            }
        }
        else if (object->GetType() == "Ellipse") {
            CEllipse* ellipse = dynamic_cast<CEllipse*>(object);
            if (ellipse) {
                ellipseArray.push_back(*ellipse);
            }
        }
        else if (object->GetType() == "Triangle") {
            CTriangle* triangle = dynamic_cast<CTriangle*>(object);
            if (triangle) {
                triangleArray.push_back(*triangle);
            }
        }
        else if (object->GetType() == "RoundRect") {
            CRoundRect* roundRect = dynamic_cast<CRoundRect*>(object);
            if (roundRect) {
                roundRectArray.push_back(*roundRect);
            }
        }
    }
    //显示信息
    void Show() const {
        int rectcount = rectArray.size();
        int ellipsecount = ellipseArray.size();
        int trianglecount = triangleArray.size();
        int roundRectCount = roundRectArray.size();
        cout << "PPT中有的图形及其信息如下" << endl;
        for (const auto& object : pages) {
            object->ShowMsg();
        }
        cout << "具体个数为:" << endl;
        cout << "矩形" << rectcount << "个" << endl;
        cout << "椭圆" << ellipsecount << "个" << endl;
        cout << "三角形" << trianglecount << "个" << endl;
        cout << "圆角矩形" << roundRectCount << "个" << endl;
        cout << "------------------------------------------------------------------------------------------------------" << endl;
        }
};
// PPT文档类
class CPPDoc {
public:
    vector<CPPage> pages;
    //构造函数
    CPPDoc() = default;

    //添加页面函数
    void AddPage() {
        pages.push_back(CPPage());
    }
    //删除指定页面
    void DeletePage(int pageIndex) {
        if (pageIndex >= 0 && pageIndex < pages.size()) {
            pages.erase(pages.begin() + pageIndex);
        }
    }
    //显示页面信息
    void ShowAllPages() const {
        for (size_t i = 0; i < pages.size(); ++i) {
            cout << "Page " << (i + 1) << " Information:" << endl;
            pages[i].Show();
        }
    }
    //复制
    void CopyPage(int sourcePageIndex, int targetPageIndex) {
        if (sourcePageIndex >= 0 && sourcePageIndex < pages.size() &&
            targetPageIndex >= 0 && targetPageIndex < pages.size()) {
            CPPage copiedPage = pages[sourcePageIndex];
            pages[targetPageIndex] = copiedPage;
        }
    }
    //粘贴
    void PastePage(int targetPageIndex, const CPPage& pageToPaste) {
        if (targetPageIndex >= 0 && targetPageIndex < pages.size()) {
            pages[targetPageIndex] = pageToPaste;
        }
    }
    //剪切
    void CutPage(int sourcePageIndex, int targetPageIndex) {
        if (sourcePageIndex >= 0 && sourcePageIndex < pages.size() &&
            targetPageIndex >= 0 && targetPageIndex < pages.size()) {
            CopyPage(sourcePageIndex, targetPageIndex);
            DeletePage(sourcePageIndex);
        }
    }
};
//将信息保存到txt文件中
void SaveToFile(int pageIndex, const string& type, const vector<int>& params, const string& text = "") {
    ofstream outFile("ppt.txt", ios::app);
    if (outFile.is_open()) {
        outFile << pageIndex << " " << type;
        for (int param : params) {
            outFile << " " << param;
        }
        if (!text.empty()) {
            outFile << " " << text;
        }
        outFile << endl;
        outFile.close();
    }
    else {
        cout << "无法打开文件ppt.txt!" << endl;
    }
}
//读取信息
void LoadFromFile(vector<CPPage>& pages) {
    ifstream inFile("ppt.txt");
    if (!inFile.is_open()) {
        ofstream createFile("ppt.txt");
        if (!createFile.is_open()) {
            cout << "无法创建文件ppt.txt!" << endl;
            return;
        }
        createFile.close();
        inFile.open("ppt.txt");
        if (!inFile.is_open()) {
            cout << "仍然无法打开文件ppt.txt!" << endl;
            return;
        }
    }
    string line;
    while (getline(inFile, line)) {
        istringstream iss(line);
        int page;
        string type;
        iss >> page >> type;    

        if (page > pages.size()) {
            pages.resize(page);
        }
        if (type == "Rect") {
            int x, y, width, height;
            string text;
            iss >> x >> y >> width >> height;
            getline(iss, text);  
            if (!text.empty() && text[0] == ' ') {
                text = text.substr(1); 
            }
            CRect* rect = new CRect(x, y, width, height, text);
            pages[page - 1].AddObject(rect);
        }
        else if (type == "Ellipse") {
            int x, y, majorAxis, minorAxis;
            string text;
            iss >> x >> y >> majorAxis >> minorAxis;
            getline(iss, text);
            CEllipse* ellipse = new CEllipse(x, y, majorAxis, minorAxis, text);
            pages[page - 1].AddObject(ellipse);
        }
        else if (type == "Triangle") {
            int x1, y1, x2, y2, x3, y3;
            string text;
            iss >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
            getline(iss, text);
            CTriangle* triangle = new CTriangle(x1, y1, x2, y2, x3, y3, text);
            pages[page - 1].AddObject(triangle);
        }
    }

    inFile.close();
}
void menu(int size) {
    cout << "菜单" << endl;
    cout << "----------------------------" << endl;
    cout << "1.添加PPT页面           |" << endl;
    cout << "2.为某个页面添加图形    |" << endl;
    cout << "3.显示某个页面的图形信息|" << endl;
    cout << "4.退出程序              |" << endl;
    cout << "* 当前页面数量:" << size << endl;
    cout << "----------------------------" << endl;
    cout << "请输入选项: ";
}
int CPPage::pagecount = 0;
int main() {
    CPPDoc doc;
    LoadFromFile(doc.pages);  
    while (true) {
        cout << "菜单" << endl;
        cout << "----------------------------" << endl;
        cout << "1.添加PPT页面           |" << endl;
        cout << "2.删除PPT页面           |" << endl;
        cout << "3.为某个页面添加图形    |" << endl;
        cout << "4.显示某个页面的图形信息|" << endl;
        cout << "5.显示所有页面信息      |" << endl;
        cout << "6.复制页面              |" << endl;
        cout << "7.粘贴页面              |" << endl;
        cout << "8.剪切页面              |" << endl;
        cout << "9.退出程序              |" << endl;
        cout << "* 当前页面数量:" << doc.pages.size() << endl;
        cout << "----------------------------" << endl;
        cout << "请输入选项: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            doc.AddPage();
            cout << "添加成功！当前页面总数为" << doc.pages.size() << endl;
        }
        else if (choice == 2) {
            if (doc.pages.empty()) {
                cout << "当前没有PPT页面，请先添加" << endl;
                continue;
            }
            int pageIndex;
            cout << "请输入要删除的页面编号 (1 - " << doc.pages.size() << "): ";
            cin >> pageIndex;
            if (pageIndex < 1 || pageIndex > doc.pages.size()) {
                cout << "无效!" << endl;
                continue;
            }
            doc.DeletePage(pageIndex - 1);
            cout << "页面删除成功！当前页面总数为" << doc.pages.size() << endl;
        }
        else if (choice == 3) {
            if (doc.pages.empty()) {
                cout << "当前没有PPT页面，请先添加" << endl;
                continue;
            }
            int pageIndex;
            cout << "请输入要添加图形的页面编号 (1 - " << doc.pages.size() << "): ";
            cin >> pageIndex;
            if (pageIndex < 1 || pageIndex > doc.pages.size()) {
                cout << "无效" << endl;
                continue;
            }
            cout << "请选择图形类型：1.矩形  2.椭圆  3.三角形" << endl;
            int shapeType;
            cin >> shapeType;
            if (shapeType == 1) {
                int x, y, width, height;
                string text;
                cout << "请输入矩形的坐标，宽度和高度：";
                cin >> x >> y >> width >> height;
                cout << "请输入矩形的文本内容：";
                cin.ignore();
                getline(cin, text);
                doc.pages[pageIndex - 1].AddObject(new CRect(x, y, width, height, text));
                SaveToFile(pageIndex, "Rect", { x, y, width, height }, text);
                cout << "矩形添加成功！" << endl;
            }
            else if (shapeType == 2) {
                int x, y, majorAxis, minorAxis;
                string text;
                cout << "请输入椭圆的坐标，长半轴和短半轴：";
                cin >> x >> y >> majorAxis >> minorAxis;
                cout << "请输入椭圆的文本内容：";
                cin.ignore();
                getline(cin, text);
                doc.pages[pageIndex - 1].AddObject(new CEllipse(x, y, majorAxis, minorAxis, text));
                SaveToFile(pageIndex, "Ellipse", { x, y, majorAxis, minorAxis }, text);
                cout << "椭圆添加成功！" << endl;
            }
            else if (shapeType == 3) {
                int x1, y1, x2, y2, x3, y3;
                string text;
                cout << "请输入三角形的三个顶点坐标：";
                cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
                cout << "请输入三角形的文本内容文本内容：";
                cin.ignore();
                getline(cin, text);
                doc.pages[pageIndex - 1].AddObject(new CTriangle(x1, y1, x2, y2, x3, y3, text));
                SaveToFile(pageIndex, "Triangle", { x1, y1, x2, y2, x3, y3 }, text);
                cout << "三角形添加成功！" << endl;
            }
            else {
                cout << "无效！" << endl;
            }
        }
        else if (choice == 4) {
            if (doc.pages.empty()) {
                cout << "当前没有PPT页面，请先添加" << endl;
                continue;
            }
            int pageIndex;
            cout << "请输入要显示的页面编号：";
            cin >> pageIndex;
            if (pageIndex < 1 || pageIndex > doc.pages.size()) {
                cout << "无效！" << endl;
                continue;
            }
            doc.pages[pageIndex - 1].Show();
        }
        else if (choice == 5) {
            doc.ShowAllPages();
        }
        else if (choice == 6) {
            if (doc.pages.size() < 2) {
                cout << "至少需要两个页面才能进行复制操作，请先添加足够的页面" << endl;
                continue;
            }
            int sourcePageIndex, targetPageIndex;
            cout << "请输入源页面编号 (1 - " << doc.pages.size() << "): ";
            cin >> sourcePageIndex;
            cout << "请输入目标页面编号 (1 - " << doc.pages.size() << "): ";
            cin >> targetPageIndex;
            if (sourcePageIndex < 1 || sourcePageIndex > doc.pages.size() ||
                targetPageIndex < 1 || targetPageIndex > doc.pages.size()) {
                cout << "无效的页面编号，请重新输入" << endl;
                continue;
            }
            doc.CopyPage(sourcePageIndex - 1, targetPageIndex - 1);
            cout << "页面复制成功！" << endl;
        }
        else if (choice == 7) {
            if (doc.pages.empty()) {
                cout << "当前没有PPT页面内容可供粘贴，请先添加页面或复制内容" << endl;
                continue;
            }
            int targetPageIndex;
            cout << "请输入目标页面编号 (1 - " << doc.pages.size() << "): ";
            cin >> targetPageIndex;
            if (targetPageIndex < 1 || targetPageIndex > doc.pages.size()) {
                cout << "无效的页面编号，请重新输入" << endl;
                continue;
            }
            CPPage pageToPaste;  
            doc.PastePage(targetPageIndex - 1, pageToPaste);
            cout << "页面粘贴成功！" << endl;
        }
        else if (choice == 8) {
            if (doc.pages.size() < 2) {
                cout << "至少需要两个页面才能进行剪切操作，请先添加足够的页面" << endl;
                continue;
            }
            int sourcePageIndex, targetPageIndex;
            cout << "请输入源页面编号 (1 - " << doc.pages.size() << "): ";
            cin >> sourcePageIndex;
            cout << "请输入目标页面编号 (1 - " << doc.pages.size() << "): ";
            cin >> targetPageIndex;
            if (sourcePageIndex < 1 || sourcePageIndex > doc.pages.size() ||
                targetPageIndex < 1 || targetPageIndex > doc.pages.size()) {
                cout << "无效的页面编号，请重新输入" << endl;
                continue;
            }
            doc.CutPage(sourcePageIndex - 1, targetPageIndex - 1);
            cout << "页面剪切成功！" << endl;
        }
        else if (choice == 9) {
            cout << "程序退出。" << endl;
            exit(1);
        }
        else {
            cout << "无效，请重新输入！" << endl;
        }
    }

    return 0;
}