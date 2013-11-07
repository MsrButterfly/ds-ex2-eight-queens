#include <iostream>
#include "position.h"
#include "stack.h"
class Chessboard {
public:
	Chessboard() : size(0) {}
	Chessboard(int size) : size(size) {}
	int amountOfQueens() {
		int i, j, count = 0, layer;
		Position pos;
		for (i = 0; i < size; i++) {
			_posStack.push(Position(0, i));
#ifdef __DEBUG__
			std::cout << "layer: " << 0 << ", push: " << i << std::endl;
#endif
			j = 0;
			while (!_posStack.empty()) {
				layer = _posStack.top().x + 1;
				if (layer == size) {
					count++;
					j = _posStack.top().y + 1;
					_posStack.pop();
				} else {
					for (; j < size; j++) {
						pos = Position(layer, j);
						if (_available(pos)) {
							_posStack.push(pos);
#ifdef __DEBUG__
							std::cout << "layer: " << layer << ", push: " << j << std::endl;
#endif
							j = 0;
							break;
						}
					}
					if (j == size) {
						j = _posStack.top().y + 1;
						_posStack.pop();
					}
				}
			}
		}
		return count;
	}
private:
	bool _available(Position pos) {
		Position _pos;
		int i;
		bool available = true;
		while (!_posStack.empty()) {
			_pos = _posStack.top();
			_temStack.push(_pos);
			_posStack.pop();
			if (_pos.x == pos.x ||
			        _pos.y == pos.y ||
			        _pos.x + _pos.y == pos.x + pos.y ||
			        _pos.x - _pos.y == pos.x - pos.y) {
				available = false;
			}
		}
		while (!_temStack.empty()) {
			_pos = _temStack.top();
			_posStack.push(_pos);
			_temStack.pop();
		}
		return available;
	}
	int size;
	Stack<Position> _posStack;
	Stack<Position> _temStack;
};
