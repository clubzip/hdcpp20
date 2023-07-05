// ADL 이란 ?
// => Argument Dependent Lookup
// => 함수를 찾을때 인자가 포함된 namespace 는 자동으로 검색된다는 문법
namespace Graphics
{
	class Point {};
	void draw_pixel(const Point& p1) {}

	void set_color(int c) {}
}

int main()
{
	Graphics::Point pt;
	Graphics::draw_pixel(pt);

	draw_pixel(pt); // Graphics:: 가 없는데, 에러가 아닙니다.
					// pt가 Graphics 안에 있으므로 
					// draw_pixel 을 찾을때 자동으로  Graphics 도 검색
}