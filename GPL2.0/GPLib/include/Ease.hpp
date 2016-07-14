

class Ease {
public:
	Ease();
	~Ease(void);

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