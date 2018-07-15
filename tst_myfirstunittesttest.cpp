#include <QString>
#include <QtTest>

#include "../MyFirstQmlProject/treemodel.h"
#include "../MyFirstQmlProject/treeitem.h"

Q_DECLARE_METATYPE(TreeItem*);

class MyFirstUnitTestTest : public QObject
{
    Q_OBJECT

public:
    MyFirstUnitTestTest();

private:
    const TreeModel* m_model;

private Q_SLOTS:
    void testCase1_data();
    void testCase1();
};

MyFirstUnitTestTest::MyFirstUnitTestTest()
{
    QFile file(":/default.txt");
    file.open(QIODevice::ReadOnly);
    static TreeModel model(file.readAll());
    file.close();

    m_model = &model;
}

void MyFirstUnitTestTest::testCase1_data()
{
    QTest::addColumn<TreeItem*>("actualItem");
    QTest::addColumn<QString>("expectedData0");
    QTest::addColumn<QString>("expectedData1");

    auto parentIndex = m_model->index(0, 0);
    auto item0 = static_cast<TreeItem*>(parentIndex.internalPointer());
    auto item00 = static_cast<TreeItem*>(m_model->index(0, 0, parentIndex).internalPointer());
    auto item01 = static_cast<TreeItem*>(m_model->index(1, 0, parentIndex).internalPointer());

    QTest::newRow("node 0") << item0 << "Getting Started" << "How to familiarize yourself with Qt Designer";
    QTest::newRow("node 00") << item00 << "Launching Designer" << "Running the Qt Designer application";
    QTest::newRow("node 01") << item01 << "The User Interface" << "How to interact with Qt Designer";
}

void MyFirstUnitTestTest::testCase1()
{
    QFETCH(TreeItem*, actualItem);
    QFETCH(QString, expectedData0);
    QFETCH(QString, expectedData1);
    QCOMPARE(actualItem->data(0).toString(), expectedData0);
    QCOMPARE(actualItem->data(1).toString(), expectedData1);
}

QTEST_APPLESS_MAIN(MyFirstUnitTestTest)

#include "tst_myfirstunittesttest.moc"
