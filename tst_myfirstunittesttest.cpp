#include <QString>
#include <QtTest>

class MyFirstUnitTestTest : public QObject
{
    Q_OBJECT

public:
    MyFirstUnitTestTest();

private Q_SLOTS:
    void testCase1_data();
    void testCase1();
};

MyFirstUnitTestTest::MyFirstUnitTestTest()
{
}

void MyFirstUnitTestTest::testCase1_data()
{
    QTest::addColumn<QString>("data");
    QTest::newRow("0") << QString();
}

void MyFirstUnitTestTest::testCase1()
{
    QFETCH(QString, data);
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(MyFirstUnitTestTest)

#include "tst_myfirstunittesttest.moc"
