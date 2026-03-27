#pragma once

#include <vector>

#include "core/button_types.h"

// MAJOR WIP, TEMPORARY FOR DEBUG
namespace core {
	class AppState {
		// TODO: figure out a proper API for this
	public:
		TransitionType m_transitionState{};
		EqualizerType m_eqState{};
		VolumeType m_volumeState{};
		EffectType m_effectState{};

		std::vector<float> m_firstTrackWaveform{};
		std::vector<float> m_secondTrackWaveform{};
		int m_mixOffset{};
	};
}
