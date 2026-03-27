#pragma once

enum class TransitionType {
	kCustom,
	// TODO: auto?
	kFade,
	kRise,
	kBlend,
	kWave,
	kMelt,
	kSlam,
	kNone,
};

enum class VolumeType {
	kSmoothCrossfade,
	kOverlap,
	kFadeInFadeOut,
	kCutInFadeOut,
	kFadeInCutOut,
	kCenterCut,
	kCrossfade,
	kFadeInFastOut,
};

enum class EqualizerType {
	kCenterBass,
	kEndBass,
	kStartBass,
	kThreeBand,
	kQuickBass,
	kLongBass,
	kNone,
};

enum class EffectType {
	kLowPassFilterOut,
	kLowPassFilterIn,
	kLowPassFilterInLowPassFilterOut,
	kLowPassFilterInHighPassFilterOut,
	kHighPassFilterOut,
	kHighPassFilterIn,
	kHighPassFilterInLowPassFilterOut,
	kHighPassFilterInHighPassFilterOut,
	kNone
};
