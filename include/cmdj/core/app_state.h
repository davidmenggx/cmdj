#pragma once

#include <vector>
#include <random>

#include "core/button_types.h"

// MAJOR WIP, TEMPORARY FOR DEBUG
namespace core {
	class AppState {
		// TODO: figure out a proper API for this
	public:
		AppState() {
			// mock some random waveform data for now
			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_real_distribution<float> distr(0.0, 1.0);

			for (long long i{ 0 }; i < 5000; ++i) {
				m_first_track_waveform.push_back(distr(gen));
				m_second_track_waveform.push_back(distr(gen));
			}
		}

		TransitionType m_transition_state{};
		EqualizerType m_eq_state{};
		VolumeType m_volume_state{};
		EffectType m_effect_state{};

		std::vector<float> m_first_track_waveform{};
		long long m_first_track_offset{ 4800ll };
		std::vector<float> m_second_track_waveform{};
		long long m_second_track_offset{ -50ll };
	};
}
