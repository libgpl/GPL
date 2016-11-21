/*
========================================================
GPL - Game Programming Library
by Luan Carlos Nesi (2014-2016)
https://github.com/libgpl
========================================================

The MIT License (MIT)

Copyright (c) 2014-2016 Luan Nesi

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#define ease Ease::getInstance()


class Ease {
private:
	Ease();
	static Ease* instance;
public:
	~Ease(void);

	static Ease* getInstance();

	float InLinear(float time, float duration, float begin, float end);
	float OutLinear(float time, float duration, float begin, float end);
	float InOutLinear(float time, float duration, float begin, float end);

	float InSin(float time, float duration, float begin, float end);
	float OutSin(float time, float duration, float begin, float end);
	float InOutSin(float time, float duration, float begin, float end);

	float InQuad(float time, float duration, float begin, float end);
	float OutQuad(float time, float duration, float begin, float end);
	float InOutQuad(float time, float duration, float begin, float end);

	float InCubic(float time, float duration, float begin, float end);
	float OutCubic(float time, float duration, float begin, float end);
	float InOutCubic(float time, float duration, float begin, float end);

	float InQuartic(float time, float duration, float begin, float end);
	float OutQuartic(float time, float duration, float begin, float end);
	float InOutQuartic(float time, float duration, float begin, float end);

	float InQuintic(float time, float duration, float begin, float end);
	float OutQuintic(float time, float duration, float begin, float end);
	float InOutQuintic(float time, float duration, float begin, float end);

	float InExponential(float time, float duration, float begin, float end);
	float OutExponential(float time, float duration, float begin, float end);
	float InOutExponential(float time, float duration, float begin, float end);

	float InCircular(float time, float duration, float begin, float end);
	float OutCircular(float time, float duration, float begin, float end);
	float InOutCircular(float time, float duration, float begin, float end);

	float InBack(float time, float duration, float begin, float end);
	float OutBack(float time, float duration, float begin, float end);
	float InOutBack(float time, float duration, float begin, float end);

	float InElastic(float time, float duration, float begin, float end);
	float OutElastic(float time, float duration, float begin, float end);
	float InOutElastic(float time, float duration, float begin, float end);

	float InBounce(float time, float duration, float begin, float end);
	float OutBounce(float time, float duration, float begin, float end);
	float InOutBounce(float time, float duration, float begin, float end);
};

