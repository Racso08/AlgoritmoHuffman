#include "FileLoader.h"
#include "CharFreqInVector.h"
#include "LeafNode.h"
#include "TreeFromListConstruction.h"
#include "GenerateHuffFile.h"
#include "Decompressor.h"
//#include <crtdbg.h>
#include <list>
#include <fstream>

int main() {
	{
		vector<char> vFile;
		vector<char> cvFile;
		vector<char> charByte;
		vector<int> frequency;

		FileLoader File("/home/racso/Odessey/VideoPlayer/Seleccionado.txt");

		vFile = File.loadFileIntoVector();

		CharFreqInVector Frequency(vFile);

		Frequency.calculateFrequency();

		charByte = Frequency.getEachChar();//Frequency.getEachChar(); // need copies of the char and its frequency to put to a LeafNode
		frequency = Frequency.getEachFrequency();//Frequency.getEachFrequency();

		TreeFromListConstruction tree(charByte, frequency);


		//passing into a class that can modify the list into a binary tree

		tree.formTree(); //modify the list into a binary tree

		GenerateHuffFile Huff(tree.getTree(), vFile, "/home/racso/Odessey/VideoPlayer/compressed.txt", charByte,
							  frequency);

		Huff.writeHuffFile();

		std::cout<<"Se termino la compresion";
///////////////////////////////////////////////////////////////////////////////////////decompression time


	FileLoader cFile("/home/racso/Odessey/VideoPlayer/compressed.txt");

	cvFile = cFile.loadFileIntoVector();

	CharFreqInVector Formated(cvFile);

	Formated.calcFreqInCompressed();

	charByte = Formated.getEachChar();//Frequency.getEachChar(); // need copies of the char and its frequency to put to a LeafNode 
	frequency = Formated.getEachFrequency();//Frequency.getEachFrequency();

	TreeFromListConstruction recontructedTree(charByte, frequency);	

	recontructedTree.formTree();

	Decompressor uncompress(recontructedTree.getTree(), cvFile, "/home/racso/Odessey/VideoPlayer/compressed.txt", "/home/racso/Odessey/VideoPlayer/decompressed.txt", vFile.size());

	uncompress.remakeFile();
	}
	//cout << _CrtDumpMemoryLeaks(); //no memory leaks yay!

		system("pause");

		return 0;
	}
