#include "FileTokenizer.h"

FTokenizer::FTokenizer(char* fname) {
	_f.open(fname);
	_pos = 0;
	_blockPos = 0;
	_more = false;
}

bool FTokenizer::more() {
	return _more;
}

int FTokenizer::pos() {
	return _pos;
}

int FTokenizer::block_pos() {
	return _blockPos;
}

bool FTokenizer::get_new_block() {
	//creates a text variable which will contain  the whole block
	char* text = new char[MAX_BLOCK];
	//if were not at the end of the file then get another block and update
	//our position
	if (!_f.eof()) {
		_pos += MAX_BLOCK;
		_f.read(text, MAX_BLOCK-1);
		text[_f.gcount()] = '\0';
		this->_stk.set_string(text);
		_more = true;
		return true;
	} else {
		//this only runs if we are at the end of the file in which case we say were done
		//and close the file
		_f.close();
		_more = false;
		return false;
	}
}

Token FTokenizer::next_token() {
	Token temp;
	_stk >> temp;
	return temp;
}

FTokenizer& operator >> (FTokenizer& f, Token& t) {
	//if the blockposition and position are the same then that means
	//we are at the end of the block so go and get a new block
	if (f._blockPos == f._pos) {
		f.get_new_block();
	}
	string temp = "";
	t = f.next_token();
	temp = t.token_str();
	f._blockPos += temp.length();

	return f;
}


