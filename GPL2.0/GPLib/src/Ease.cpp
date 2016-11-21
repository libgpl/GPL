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
#include "../include/Ease.hpp"
#include <math.h>

#ifndef PI
#define PI 3.14159265358979
#endif

using namespace std;

//OutElastic
//InCircular
//InCubic
//InElastic
//InOutElastic

Ease::Ease()
{
}

Ease::~Ease(void)
{
}

float Ease::InLinear(float time, float duration, float begin, float end)
{
	//if (time >= duration) time = 0;
	end = end - begin;
	return (end * time / duration) + begin;
}

float Ease::OutLinear(float time, float duration, float begin, float end)
{
	end = end - begin;
	return (end * time / duration) + begin;
}

float Ease::InOutLinear(float time, float duration, float begin, float end)
{
	end = end - begin;
	return (end * time / duration) + begin;
}

//	seno
float Ease::InSin(float time, float duration, float begin, float end)
{
	end = end - begin;
	return -end * (float)cos(time / duration * (PI / 2.0f)) + end + begin;
}

float Ease::OutSin(float time, float duration, float begin, float end)
{
	end = end - begin;
	return end * (float)sin(time / duration * (PI / 2.0f)) + begin;
}

float Ease::InOutSin(float time, float duration, float begin, float end)
{
	end = end - begin;
	return -end / 2.0f * (float)(cos(PI*time / duration) - 1) + begin;
}

//	quadrático
float Ease::InQuad(float time, float duration, float begin, float end)
{
	end = end - begin;
	return end * (time /= duration)*time + begin;
}

float Ease::OutQuad(float time, float duration, float begin, float end)
{
	end = end - begin;
	return -end * (time /= duration)*(time - 2.0f) + begin;
}

float Ease::InOutQuad(float time, float duration, float begin, float end)
{
	end = end - begin;
	if ((time /= duration / 2.0f) < 1)
		return end / 2.0f * time*time + begin;

	return -end / 2.0f * ((--time)*(time - 2.0f) - 1) + begin;
}

//	cúbico
float Ease::InCubic(float time, float duration, float begin, float end)
{
	end = end - begin;
	return end*(time)*time*time + begin;
}

float Ease::OutCubic(float time, float duration, float begin, float end)
{
	end = end - begin;
	return end*((time = time / duration - 1)*time*time + 1) + begin;
}

float Ease::InOutCubic(float time, float duration, float begin, float end)
{
	end = end - begin;
	if ((time /= duration / 2.0f) < 1)
		return end / 2.0f * time*time*time + begin;

	return end / 2.0f * ((time -= 2.0f)*time*time + 2.0f) + begin;
}

//	quártico
float Ease::InQuartic(float time, float duration, float begin, float end)
{
	end = end - begin;
	return end * (time /= duration)*time*time*time + begin;
}

float Ease::OutQuartic(float time, float duration, float begin, float end)
{
	end = end - begin;
	return -end * ((time = time / duration - 1)*time*time*time - 1) + begin;
}

float Ease::InOutQuartic(float time, float duration, float begin, float end)
{
	end = end - begin;
	if ((time /= duration / 2.0f) < 1)
		return end / 2.0f * time*time*time*time + begin;

	return -end / 2.0f * ((time -= 2.0f)*time*time*time - 2.0f) + begin;
}

//	quíntico
float Ease::InQuintic(float time, float duration, float begin, float end)
{
	end = end - begin;
	return end*(time /= duration)*time*time*time*time + begin;
}

float Ease::OutQuintic(float time, float duration, float begin, float end)
{
	end = end - begin;
	return end*((time = time / duration - 1)*time*time*time*time + 1) + begin;
}

float Ease::InOutQuintic(float time, float duration, float begin, float end)
{
	end = end - begin;
	if ((time /= duration / 2.0f) < 1)
		return end / 2.0f * time*time*time*time*time + begin;

	return end / 2.0f * ((time -= 2.0f)*time*time*time*time + 2.0f) + begin;
}

//	exponencial base 2
float Ease::InExponential(float time, float duration, float begin, float end)
{
	end = end - begin;
	return (time == 0) ? begin : end * (float)pow(2, 10 * (time / duration - 1)) + begin;
}

float Ease::OutExponential(float time, float duration, float begin, float end)
{
	end = end - begin;
	return (time == duration) ? begin + end : end * (-(float)pow(2, -10 * time / duration) + 1) + begin;
}

float Ease::InOutExponential(float time, float duration, float begin, float end)
{
	end = end - begin;
	if (time == 0)
		return begin;

	if (time == duration)
		return begin + end;

	if ((time /= duration / 2.0f) < 1)
		return end / 2.0f * (float)pow(2, 10 * (time - 1)) + begin;

	return end / 2.0f * (-(float)pow(2, -10 * --time) + 2) + begin;
}

//	circular
float Ease::InCircular(float time, float duration, float begin, float end)
{
	end = end - begin;
	return -end * ((float)sqrt(1 - (time /= duration)*time) - 1) + begin;
}

float Ease::OutCircular(float time, float duration, float begin, float end)
{
	end = end - begin;
	return end * (float)sqrt(1 - (time = time / duration - 1)*time) + begin;
}

float Ease::InOutCircular(float time, float duration, float begin, float end)
{
	end = end - begin;
	if ((time /= duration / 2.0f) < 1)
		return -end / 2.0f * ((float)sqrt(1 - time*time) - 1) + begin;

	return end / 2.0f * ((float)sqrt(1 - (time -= 2)*time) + 1) + begin;
}

//	cúbico excedido
float Ease::InBack(float time, float duration, float begin, float end)
{
	end = end - begin;
	float s = 1.70158f;
	return end*(time /= duration)*time*((s + 1)*time - s) + begin;
}

float Ease::OutBack(float time, float duration, float begin, float end)
{
	end = end - begin;
	float s = 1.70158f;
	return end*((time = time / duration - 1)*time*((s + 1)*time + s) + 1) + begin;
}

float Ease::InOutBack(float time, float duration, float begin, float end)
{
	end = end - begin;
	float s = 1.70158f;
	if ((time /= duration / 2.0f) < 1)
		return end / 2.0f * (time*time*(((s *= (1.525f)) + 1)*time - s)) + begin;

	return end / 2.0f * ((time -= 2.0f)*time*(((s *= (1.525f)) + 1)*time + s) + 2.0f) + begin;
}

//	seno exponencial amortecida
float Ease::InElastic(float time, float duration, float begin, float end)
{
	end = end - begin;
	float s = 1.70158f;
	float p = 0.0f;
	float a = end;

	if (time == 0)
		return begin;
	if ((time /= duration) == 1)
		return begin + end;
	if (!p)
		p = duration*.3f;

	if (a < fabsf(end))
	{
		a = end;
		s = p / 4.0f;
	}
	else
	{
		s = p / (2.0f * (float)PI) * (float)asin(end / a);
	}

	return -(a*(float)pow(2, 10 * (time -= 1)) * (float)sin((time*duration - s)*(2.0f * PI) / p)) + begin;
}

float Ease::OutElastic(float time, float duration, float begin, float end)
{
	end = end - begin;
	float s = 1.70158f;
	float p = 0.0f;
	float a = end;

	if (time == 0)
		return begin;
	if ((time /= duration) == 1)
		return begin + end;
	if (!p)
		p = duration*.3f;

	if (a < fabsf(end))
	{
		a = end;
		s = p / 4.0f;
	}
	else
	{
		s = p / (2.0f * (float)PI) * (float)asin(end / a);
	}

	return a*(float)pow(2, -10 * time) * (float)sin((time*duration - s)*(2.0f * PI) / p) + end + begin;
}

float Ease::InOutElastic(float time, float duration, float begin, float end)
{
	end = end - begin;
	float s = 1.70158f;
	float p = 0.0f;
	float a = end;

	if (time == 0)
		return begin;
	if ((time /= duration / 2.0f) == 2.0f)
		return begin + end;
	if (!p) p = duration*(.3f*1.5f);

	if (a < fabsf(end))
	{
		a = end;
		s = p / 4.0f;
	}
	else
	{
		s = p / (2.0f * (float)PI) * (float)asin(end / a);
	}

	if (time < 1)
		return -.5f*(a*(float)pow(2, 10 * (time -= 1)) * (float)sin((time*duration - s)*(2.0f * PI) / p)) + begin;

	return a*(float)pow(2, -10 * (time -= 1)) * (float)sin((time*duration - s)*(2.0f * PI) / p)*.5f + end + begin;
}

//	 exponencial decadente

float Ease::OutBounce(float time, float duration, float begin, float end)
{
	end = end - begin;
	if ((time /= duration) < (1.0f / 2.75f))
		return end*(7.5625f*time*time) + begin;
	else if (time < (2.0f / 2.75f))
		return end*(7.5625f*(time -= (1.5f / 2.75f))*time + .75f) + begin;
	else if (time < (2.5f / 2.75f))
		return end*(7.5625f*(time -= (2.25f / 2.75f))*time + .9375f) + begin;
	else
		return end*(7.5625f*(time -= (2.625f / 2.75f))*time + .984375f) + begin;
}

float Ease::InBounce(float time, float duration, float begin, float end)
{
	end = end - begin;
	return end - OutBounce(duration - time, duration, 0, end) + begin;
}

float Ease::InOutBounce(float time, float duration, float begin, float end)
{
	end = end - begin;
	if (time < duration / 2.0f)
		return InBounce(time * 2.0f, duration, 0, end) * .5f + begin;

	return OutBounce(time * 2.0f - duration, duration, 0, end) * .5f + end*.5f + begin;
}

Ease* Ease::getInstance()
{
	if (!instance)
	{
		instance = new Ease();
	}
	return instance;
}



Ease* Ease::instance = NULL;