#include "pch.h"
#include "CppUnitTest.h"
#include "../lab5.4/lab5.4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest54
{
	TEST_CLASS(UnitTest54)
	{
	public:

                int N = 5; // Параметр для тестування
                int limit = 10; // Межа для циклів

                // Еталонна (reference) функція для порівняння
                double referenceP(const int N) {
                    double p = 1;
                    for (int i = N; i <= 10; i++) {
                        p *= (i + 1.0 / (i * i)) / sqrt(1 + exp(i));
                    }
                    return p;
                }

                // Тест для P0
                TEST_METHOD(TestP0) {
                    Assert::AreEqual(referenceP(N), P0(N), 0.0000000000001);
                }

                // Тест для P1 (рекурсивне збільшення)
                TEST_METHOD(TestP1) {
                    Assert::AreEqual(referenceP(N), P1(N, N), 0.0000000000001);
                }

                // Тест для P2 (рекурсивне зменшення)
                TEST_METHOD(TestP2) {
                    Assert::AreEqual(referenceP(N), P2(10, N), 0.0000000000001);
                }

                // Тест для P3 (рекурсивне збільшення з додатковим параметром)
                TEST_METHOD(TestP3) {
                    Assert::AreEqual(referenceP(N), P3(N, 10, 1), 0.0000000000001);
                }

                // Тест для P4 (рекурсивне зменшення з додатковим параметром)
                TEST_METHOD(TestP4) {
                    Assert::AreEqual(referenceP(N), P4(10, N, 1), 0.0000000000001);
                }
            };
        }

		