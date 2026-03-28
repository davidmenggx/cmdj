#pragma once

#include <vector>

#include "core/button_types.h"

// MAJOR WIP, TEMPORARY FOR DEBUG
namespace core {
	class AppState {
		// TODO: figure out a proper API for this
	public:
		TransitionType m_transition_state{};
		EqualizerType m_eq_state{};
		VolumeType m_volume_state{};
		EffectType m_effect_state{};

		std::vector<float> m_first_track_waveform{};
		std::vector<float> m_second_track_waveform{};
		int m_mix_offset{};
	};
}
