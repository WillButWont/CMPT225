all: AddLeftTest AddRightTest RemoveLeftTest RemoveRightTest

AddLeftTest: AddLeftTest.cpp
	g++ -Wall -o AddLeftTest AddLeftTest.cpp

AddRightTest: AddRightTest.cpp
	g++ -Wall -o AddRightTest AddRightTest.cpp

RemoveLeftTest: RemoveLeftTest.cpp
	g++ -Wall -o RemoveLeftTest RemoveLeftTest.cpp

RemoveRightTest: RemoveRightTest.cpp
	g++ -Wall -o RemoveRightTest RemoveRightTest.cpp

run:
	-./AddLeftTest
	-./AddRightTest
	-./RemoveLeftTest
	-./RemoveRightTest

clean:
	rm -f AddLeftTest AddRightTest RemoveLeftTest RemoveRightTest
