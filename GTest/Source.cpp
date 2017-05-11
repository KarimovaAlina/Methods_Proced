
#include "main.h"
#include <iostream>
#include <fstream>
#include <string>
#include "gtest/gtest.h"

using namespace std;

bool CompareFiles(ifstream &f1, ifstream &f2)
{
	string s1;
	string s2;
	int i = 0;
	while ((!f1.eof()) || (!f2.eof()))
	{
		getline(f1, s1);
		getline(f2, s2);
		if (s1 != s2)
		{
			cout << "String " << i + 1 << "don't match!\n" << s1 << "\n" << s2 << "\n";
			return false;
		}
		i += 1;
	}
	return true;
}

TEST(SphereTest, SphereIn)
{
	ifstream file("SphereIn.txt");
	sphere *actual = new sphere, *expected;
	expected = new sphere;
	In(*actual, file);
	expected->rad = 7;
	EXPECT_TRUE(actual->rad == expected->rad);
}

TEST(SphereTest, SphereOut)
{
	ofstream file("SphereOut.txt");
	sphere* s = new sphere;
	s->t = SPHERE;
	s->rad = 4;
	Out(*s, file);
	file.close();
	ifstream actualFile("SphereOut.txt"), expectedFile("SphereOutPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
}

TEST(SphereTest, SphereVolume)
{
	sphere *actual = new sphere;
	actual->t = SPHERE;
	actual->rad = 5;
	float ActualVolume = Volume(actual);
	float ExpectedVolume = 5 * 5 * 5 * 3.1415 * 4 / 3;
	EXPECT_TRUE(abs(ActualVolume - ExpectedVolume) < 0.00001);
}

TEST(ParallelepipedTest, ParallelepipedIn)
{
	ifstream file("ParallelepipedIn.txt");
	parallelepiped *actual = new parallelepiped, *expected;
	expected = new parallelepiped;
	In(*actual, file);
	expected->t = PARALLELEPIPED;
	expected->e1 = 2;
	expected->e2 = 3;
	expected->e3 = 4;
	EXPECT_TRUE(actual->e1 == expected->e1);
	EXPECT_TRUE(actual->e2 == expected->e2);
	EXPECT_TRUE(actual->e3 == expected->e3);
}

TEST(ParallelepipedTest, ParallelepipedOut)
{
	ofstream file("ParallelepipedOut.txt");
	parallelepiped* p = new parallelepiped;
	p->t = PARALLELEPIPED;
	p->e1 = 4;
	p->e2 = 10;
	p->e3 = 8;
	Out(*p, file);
	file.close();
	ifstream actualFile("ParallelepipedOut.txt"), expectedFile("ParallelepipedOutPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
}

TEST(ParallelepipedTest, ParallelepipedVolume)
{
	parallelepiped* actual = new parallelepiped;
	actual->t = PARALLELEPIPED;
	actual->e1 = 4;
	actual->e2 = 10;
	actual->e3 = 8;
	float ActualVolume = Volume(actual);
	float ExpectedVolume = 4 * 10 * 8;
	EXPECT_TRUE(abs(ActualVolume - ExpectedVolume) < 0.00001);
}

TEST(TetrahedronTest, TetrahedronIn)
{
	ifstream file("TetrahedronIn.txt");
	tetrahedron *actual = new tetrahedron, *expected;
	expected = new tetrahedron;
	In(*actual, file);
	expected->t = TETRAHEDRON;
	expected->side = 2;
	EXPECT_TRUE(actual->side == expected->side);
}

TEST(TetrahedronTest, TetrahedronOut)
{
	ofstream file("TetrahedronOut.txt");
	tetrahedron* t = new tetrahedron;
	t->t = TETRAHEDRON;
	t->side = 4;

	Out(*t, file);
	file.close();
	ifstream actualFile("TetrahedronOut.txt"), expectedFile("TetrahedronOutPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
}

TEST(TetrahedronTest, TetrahedronVolume)
{
	tetrahedron* actual = new tetrahedron;
	actual->t = TETRAHEDRON;
	actual->side = 7;
	float ActualVolume = Volume(actual);
	float ExpectedVolume = 7 * 7 * 7 * sqrt((double)2) / 12;
	EXPECT_TRUE(abs(ActualVolume - ExpectedVolume) < 0.00001);
}

TEST(InputShapeTest, InputSphereInShape)
{
	ifstream file("InputSphereInShape.txt");
	shape *actual = In(file);
	shape *expected = new shape;
	((sphere *)expected)->rad = 2;
	expected->t = SPHERE;
	expected->destiny = 100;
	expected->temp = 650;
	EXPECT_TRUE(((sphere *)expected)->rad == ((sphere *)actual)->rad);
	EXPECT_TRUE(expected->t == actual->t);
	EXPECT_TRUE(expected->destiny == actual->destiny);
	EXPECT_TRUE(expected->temp == actual->temp);
}

TEST(InputShapeTest, InputParallelepipedInShape)
{
	ifstream file("InputParallelepipedInShape.txt");
	shape *actual = In(file);
	shape *expected = new shape;
	((parallelepiped *)expected)->e1 = 5;
	((parallelepiped *)expected)->e2 = 6;
	((parallelepiped *)expected)->e3 = 8;
	expected->t = PARALLELEPIPED;
	expected->destiny = 90;
	expected->temp = 678;
	EXPECT_TRUE(((parallelepiped *)expected)->e1 == ((parallelepiped *)actual)->e1);
	EXPECT_TRUE(((parallelepiped *)expected)->e2 == ((parallelepiped *)actual)->e2);
	EXPECT_TRUE(((parallelepiped *)expected)->e3 == ((parallelepiped *)actual)->e3);
	EXPECT_TRUE(expected->t == actual->t);
	EXPECT_TRUE(expected->destiny == actual->destiny);
	EXPECT_TRUE(expected->temp == actual->temp);
}

TEST(InputShapeTest, InputTetrahedronInShape)
{
	ifstream file("InputTetrahedronInShape.txt");
	shape *actual = In(file);
	shape *expected = new shape;
	((tetrahedron *)expected)->side = 30;
	expected->t = TETRAHEDRON;
	expected->destiny = 90;
	expected->temp = 654;
	EXPECT_TRUE(((tetrahedron *)expected)->side == ((tetrahedron *)actual)->side);
	EXPECT_TRUE(expected->t == actual->t);
	EXPECT_TRUE(expected->destiny == actual->destiny);
	EXPECT_TRUE(expected->temp == actual->temp);
}

TEST(OutputShapeTest, ShapeParallelepipedOutput)
{
	ofstream file("ShapeParallelepipedOut.txt");
	shape *p = new shape;
	((parallelepiped*)p)->t = PARALLELEPIPED;
	((parallelepiped *)p)->e1 = 2;
	((parallelepiped *)p)->e2 = 3;
	((parallelepiped *)p)->e3 = 4;
	p->destiny = 50;
	p->temp = 600;
	Out(p, file);
	file.close();
	ifstream actualFile("ShapeParallelepipedOut.txt"), expectedFile("ShapeParallelepipedOutPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
}

TEST(OutputShapeTest, ShapeSphereOut)
{
	ofstream file("ShapeSphereOut.txt");
	shape *s = new shape;
	((sphere*)s)->t = SPHERE;
	((sphere *)s)->rad = 5;
	s->destiny = 20;
	s->temp = 700;
	Out(s, file);
	file.close();
	ifstream actualFile("ShapeSphereOut.txt"), expectedFile("ShapeSphereOutPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
}

TEST(OutputShapeTest, ShapeTetrahedronOut)
{
	ofstream file("ShapeTetrahedronOut.txt");
	shape *s = new shape;
	((tetrahedron*)s)->t = TETRAHEDRON;
	((tetrahedron *)s)->side = 7;
	s->destiny = 50;
	s->temp = 6500;
	Out(s, file);
	file.close();
	ifstream actualFile("ShapeTetrahedronOut.txt"), expectedFile("ShapeTetrahedronOutPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
}

TEST(ShapeVolumeTest, ShapeSphereVolume)
{
	shape *actual = new shape;
	((sphere*)actual)->t = SPHERE;
	((sphere*)actual)->rad = 5;
	float ActualVolume = Volume(actual);
	float ExpectedVolume = 5 * 5 * 5 * 3.1415 * 4 / 3;
	EXPECT_TRUE(abs(ActualVolume - ExpectedVolume) < 0.00001);
}

TEST(ShapeVolumeTest, ShapeBoxVolume)
{
	shape *actual = new shape;
	((parallelepiped*)actual)->t = PARALLELEPIPED;
	((parallelepiped*)actual)->e1 = 8;
	((parallelepiped*)actual)->e2 = 6;
	((parallelepiped*)actual)->e3 = 10;
	float ActualVolume = Volume(actual);
	float ExpectedVolume = 8 * 6 * 10;
	EXPECT_EQ(ExpectedVolume, ActualVolume);
}

TEST(ShapeVolumeTest, ShapeTetrahedronVolume)
{
	shape *actual = new shape;
	((tetrahedron*)actual)->t = TETRAHEDRON;
	((tetrahedron*)actual)->side = 7;
	float ActualVolume = Volume(actual);
	float ExpectedVolume = 7 * 7 * 7 * sqrt((double)2) / 12;
	EXPECT_TRUE(abs(ActualVolume - ExpectedVolume) < 0.0001);
}

TEST(ShapeCompareVolumeTest, CompareVolumeMore)
{
	shape *s1 = new shape;
	((tetrahedron*)s1)->t = TETRAHEDRON;
	((tetrahedron*)s1)->side = 3;

	shape *s2 = new shape;
	((parallelepiped*)s2)->t = PARALLELEPIPED;
	((parallelepiped*)s2)->e1 = 7;
	((parallelepiped*)s2)->e2 = 6;
	((parallelepiped*)s2)->e3 = 2;
	EXPECT_TRUE(Compare(s1, s2));
}

TEST(ShapeCompareVolumeTest, CompareVolumeLess)
{
	shape *s1 = new shape;
	((tetrahedron*)s1)->t = TETRAHEDRON;
	((tetrahedron*)s1)->side = 9;

	shape *s2 = new shape;
	((parallelepiped*)s2)->t = PARALLELEPIPED;
	((parallelepiped*)s2)->e1 = 7;
	((parallelepiped*)s2)->e2 = 6;
	((parallelepiped*)s2)->e3 = 2;
	EXPECT_TRUE(!Compare(s1, s2));
}


TEST(ShapeCompareVolumeTest, CompareVolumeEqually)
{
	shape *s = new shape;
	((parallelepiped*)s)->t = PARALLELEPIPED;
	((parallelepiped*)s)->e1 = 7;
	((parallelepiped*)s)->e2 = 6;
	((parallelepiped*)s)->e3 = 2;
	EXPECT_TRUE(!Compare(s, s));
}

TEST(ClearContainerTest, ClearEmptyContainer)
{
	container *c = new container;
	c->cont = NULL;
	c->n = 0;

	ClearContainer(*c);
	EXPECT_TRUE(c->cont == NULL);
	EXPECT_EQ(c->n, 0);
}

TEST(ClearContainerTest, ClearNonEmptyContainer)
{
	container *c = new container;
	c->cont = new list;
	c->cont->shape = new shape;
	
	c->n = 1;

	ClearContainer(*c);
	EXPECT_TRUE(c->cont == NULL);
	EXPECT_EQ(c->n, 0);
}

TEST(InputContainerTest, OneSphereInContainer)
{
	ifstream file("OneSphereInContainer.txt");
	container *actual = new container;
	actual->n = 0;
	actual->cont = NULL;
	In(*actual, file);
	container *expected = new container;
	expected->n = 1;
	expected->cont = new list;
	expected->cont->next = NULL;
	expected->cont->shape = new shape;
	expected->cont->shape->t = SPHERE;
	expected->cont->shape->destiny = 100;
	expected->cont->shape->temp = 650;
	((sphere*)expected->cont->shape)->rad = 2;
	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(InputContainerTest, OneTetrahedronInContainer)
{
	ifstream file("OneTetrahedronInContainer.txt");
	container *actual = new container;
	actual->n = 0;
	actual->cont = NULL;
	In(*actual, file);
	container *expected = new container;
	expected->n = 1;
	expected->cont = new list;
	expected->cont->next = NULL;
	expected->cont->shape = new shape;
	expected->cont->shape->t = TETRAHEDRON;
	expected->cont->shape->destiny = 100;
	expected->cont->shape->temp = 650;
	((tetrahedron*)expected->cont->shape)->side = 5;
	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(InputContainerTest, OneParallelepipedInContainer)
{
	ifstream file("OneParallelepipedInContainer.txt");
	container *actual = new container;
	actual->n = 0;
	actual->cont = NULL;
	In(*actual, file);
	container *expected = new container;
	expected->n = 1;
	expected->cont = new list;
	expected->cont->next = NULL;
	expected->cont->shape = new shape;
	expected->cont->shape->t = PARALLELEPIPED;
	expected->cont->shape->destiny = 100;
	expected->cont->shape->temp = 650;
	((parallelepiped*)expected->cont->shape)->e1 = 5;
	((parallelepiped*)expected->cont->shape)->e2 = 6;
	((parallelepiped*)expected->cont->shape)->e3 = 7;
	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(InputContainerTest, NoElementsInContainer)
{
	ifstream file("NoElementsInContainer.txt");
	container *actual = new container;
	actual->cont = NULL;
	actual->n = 0;
	In(*actual, file);

	container *expected = new container;
	expected->cont = NULL;
	expected->n = 0;
	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(InputContainerTest, SeveralElementsInContainer)
{
	ifstream file("SeveralElementsInContainer.txt");
	container *actual = new container;
	actual->cont = NULL;
	actual->n = 0;
	In(*actual, file);

	container *expected = new container;
	ContainerPattern(expected);
	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(OutputContainerTest, SeveralElementsOutContainer)
{
	ofstream file("SeveralElementOutContainer.txt");
	container *actual = new container;
	ContainerPattern(actual);
	Out(*actual, file);
	file.close();

	ifstream actualFile("SeveralElementOutContainer.txt"), expectedFile("SeveralElementOutContainerPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
}

TEST(OutputContainerTest, OneSphereOutContainer)
{
	container *actual = new container;
	actual->n = 1;
	actual->cont = new list;
	actual->cont->shape = new shape;
	actual->cont->shape->t = SPHERE;
	actual->cont->shape->destiny = 10.5;
	actual->cont->shape->temp = 25;
	((sphere*)actual->cont->shape)->rad = 25;

	ofstream file("OneSphereOutContainer.txt");
	Out(*actual, file);
	file.close();

	ifstream actualFile("OneSphereOutContainer.txt"), expectedFile("OneSphereOutContainerPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
}

TEST(OutputContainerTest, OneParallelepipedOutContainer)
{
	ofstream file("OneParallelepipedOutContainer.txt");
	container *actual = new container;
	actual->n = 1;
	actual->cont = new list;
	actual->cont->shape = new shape;
	actual->cont->shape->t = PARALLELEPIPED;
	actual->cont->shape->destiny = 15.5;
	actual->cont->shape->temp = 30;
	((parallelepiped*)actual->cont->shape)->e1 = 25;
	((parallelepiped*)actual->cont->shape)->e2 = 25;
	((parallelepiped*)actual->cont->shape)->e3 = 25;
	Out(*actual, file);
	file.close();

	ifstream actualFile("OneParallelepipedOutContainer.txt"), expectedFile("OneParallelepipedOutContainerPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
}

TEST(OutputContainerTest, OneTetrahedronOutContainer)
{
	ofstream file("OneTetrahedronOutContainer.txt");
	container *actual = new container;
	actual->n = 1;
	actual->cont = new list;
	actual->cont->shape = new shape;
	actual->cont->shape->t = TETRAHEDRON;
	actual->cont->shape->destiny = 15.5;
	actual->cont->shape->temp = 30;
	((tetrahedron*)actual->cont->shape)->side = 35;
	Out(*actual, file);
	file.close();

	ifstream actualFile("OneTetrahedronOutContainer.txt"), expectedFile("OneTetrahedronOutContainerPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
}

TEST(OutputContainerTest, NoElementsOutContainer)
{
	ofstream file("NoElementsOutContainer.txt");
	container *actual = new container;
	actual->n = 0;
	actual->cont = NULL;
	
	Out(*actual, file);
	file.close();

	ifstream actualFile("NoElementsOutContainer.txt"), expectedFile("NoElementsOutContainerPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
}

TEST(OutputContainerTest, OnlySeveralSpheresOutContainer)
{
	ofstream file("OnlySeveralSpheresOutContainer.txt");
	container *actual = new container;
	ContainerPattern(actual);
	OutSpheres(*actual, file);
	file.close();

	ifstream actualFile("OnlySeveralSpheresOutContainer.txt"), expectedFile("OnlySeveralSpheresOutContainerPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
}

TEST(OutputContainerTest, OnlySingleSphereOutContainer)
{
	ofstream file("OnlySingleSpheresOutContainer.txt");
	container *actual = new container;
	actual->n = 1;
	actual->cont = new list;
	actual->cont->shape = new shape;
	actual->cont->shape->t = SPHERE;
	actual->cont->shape->destiny = 10.5;
	actual->cont->shape->temp = 25;
	((sphere*)actual->cont->shape)->rad = 25;
	OutSpheres(*actual, file);
	file.close();

	ifstream actualFile("OnlySingleSpheresOutContainer.txt"), expectedFile("OnlySingleSpheresOutContainerPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
}

TEST(OutputContainerTest, NoSpheresOutContainer)
{
	ofstream file("NoSpheresOutContainer.txt");
	container *actual = new container;
	actual->n = 0;
	actual->cont = NULL;
	OutSpheres(*actual, file);
	file.close();

	ifstream actualFile("NoSpheresOutContainer.txt"), expectedFile("NoSpheresOutContainerPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
}

TEST(SortContainerTest, JustSortContainer)
{
	
	container *actual = new container;
	ContainerPattern(actual);
	Sort(*actual);
	
	
	container *expected = new container;
	SortedContainerPattern(expected);
	
	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(SortContainerTest, DoubleSortedContainer)
{
	container *actual = new container;
	ContainerPattern(actual);
	Sort(*actual);
	Sort(*actual);
	
	container *expected = new container;
	SortedContainerPattern(expected);

	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(SortContainerTest, OneSphereInContainer)
{
	container *actual = new container;
	actual->n = 1;
	actual->cont = new list;
	actual->cont->shape = new shape;
	actual->cont->shape->t = SPHERE;
	actual->cont->shape->destiny = 10.5;
	actual->cont->shape->temp = 25;
	((sphere*)actual->cont->shape)->rad = 25;
	Sort(*actual);

	container *expected = new container;
	expected->n = 1;
	expected->cont = new list;
	expected->cont->shape = new shape;
	expected->cont->shape->t = SPHERE;
	expected->cont->shape->destiny = 10.5;
	expected->cont->shape->temp = 25;
	((sphere*)expected->cont->shape)->rad = 25;
	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(SortContainerTest, OneParallelepipedInContainer)
{
	container *actual = new container;
	actual->n = 1;
	actual->cont = new list;
	actual->cont->shape = new shape;
	actual->cont->shape->t = PARALLELEPIPED;
	actual->cont->shape->destiny = 10.5;
	actual->cont->shape->temp = 25;
	((parallelepiped*)actual->cont->shape)->e1 = 25;
	((parallelepiped*)actual->cont->shape)->e2 = 250;
	((parallelepiped*)actual->cont->shape)->e3 = 251;
	Sort(*actual);

	container *expected = new container;
	expected->n = 1;
	expected->cont = new list;
	expected->cont->shape = new shape;
	expected->cont->shape->t = PARALLELEPIPED;
	expected->cont->shape->destiny = 10.5;
	expected->cont->shape->temp = 25;
	((parallelepiped*)expected->cont->shape)->e1 = 25;
	((parallelepiped*)expected->cont->shape)->e2 = 250;
	((parallelepiped*)expected->cont->shape)->e3 = 251;
	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(SortContainerTest, OneTetrahedronInContainer)
{
	container *actual = new container;
	actual->n = 1;
	actual->cont = new list;
	actual->cont->shape = new shape;
	actual->cont->shape->t = TETRAHEDRON;
	actual->cont->shape->destiny = 10.5;
	actual->cont->shape->temp = 25;
	((tetrahedron*)actual->cont->shape)->side = 25;
	Sort(*actual);

	container *expected = new container;
	expected->n = 1;
	expected->cont = new list;
	expected->cont->shape = new shape;
	expected->cont->shape->t = TETRAHEDRON;
	expected->cont->shape->destiny = 10.5;
	expected->cont->shape->temp = 25;
	((tetrahedron*)expected->cont->shape)->side = 25;
	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(SortContainerTest, ReversedSortContainer)
{
	container *c = new container;
	c->n = 6;
	c->cont = new list;
	list* cur = c->cont;
	cur->shape = new shape;
	cur->next = new list;
	((tetrahedron*)c->cont->shape)->t = TETRAHEDRON;
	((tetrahedron*)c->cont->shape)->side = 9;
	((tetrahedron*)c->cont->shape)->destiny = 98;
	((tetrahedron*)c->cont->shape)->temp = 354;

	cur = cur->next;
	cur->shape = new shape;
	cur->next = new list;
	((tetrahedron*)cur->shape)->t = TETRAHEDRON;
	((tetrahedron*)cur->shape)->side = 15;
	((tetrahedron*)cur->shape)->destiny = 150;
	((tetrahedron*)cur->shape)->temp = 1000;

	cur = cur->next;
	cur->shape = new shape;
	cur->next = new list;
	((parallelepiped*)cur->shape)->t = PARALLELEPIPED;
	((parallelepiped*)cur->shape)->e1 = 1;
	((parallelepiped*)cur->shape)->e2 = 10;
	((parallelepiped*)cur->shape)->e3 = 100;
	((parallelepiped*)cur->shape)->destiny = 300;
	((parallelepiped*)cur->shape)->temp = 1500;

	cur = cur->next;
	cur->shape = new shape;
	cur->next = new list;
	((sphere*)cur->shape)->t = SPHERE;
	((sphere*)cur->shape)->rad = 10;
	((sphere*)cur->shape)->destiny = 100;
	((sphere*)cur->shape)->temp = 500;

	cur = cur->next;
	cur->shape = new shape;
	cur->next = new list;
	((parallelepiped*)cur->shape)->t = PARALLELEPIPED;
	((parallelepiped*)cur->shape)->e1 = 2;
	((parallelepiped*)cur->shape)->e2 = 20;
	((parallelepiped*)cur->shape)->e3 = 200;
	((parallelepiped*)cur->shape)->destiny = 600;
	((parallelepiped*)cur->shape)->temp = 5000;
	
	cur = cur->next;
	cur->shape = new shape;
	cur->next = NULL;
	((sphere*)cur->shape)->t = SPHERE;
	((sphere*)cur->shape)->rad = 25;
	((sphere*)cur->shape)->destiny = 250;
	((sphere*)cur->shape)->temp = 3000;

	Sort(*c);

	container *expected = new container;
	SortedContainerPattern(expected);

	EXPECT_TRUE(CompareContainer(c, expected));
}

TEST(SortContainerTest, NothingInContainer)
{
	container *actual = new container;
	actual->n = 0;
	actual->cont = new list;
	actual->cont->next = NULL;
	actual->cont->shape = NULL;
	Sort(*actual);

	container *expected = new container;
	expected->n = 0;
	expected->cont = new list;
	expected->cont->next = NULL;
	expected->cont->shape = NULL;

	EXPECT_TRUE(CompareContainer(actual, expected));
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	system("pause");
	return 0;
}