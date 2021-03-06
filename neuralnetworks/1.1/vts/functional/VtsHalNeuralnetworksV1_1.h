/*
 * Copyright (C) 2018 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef VTS_HAL_NEURALNETWORKS_V1_1_H
#define VTS_HAL_NEURALNETWORKS_V1_1_H

#include <android/hardware/neuralnetworks/1.0/IExecutionCallback.h>
#include <android/hardware/neuralnetworks/1.0/IPreparedModel.h>
#include <android/hardware/neuralnetworks/1.0/IPreparedModelCallback.h>
#include <android/hardware/neuralnetworks/1.1/IDevice.h>
#include <android/hardware/neuralnetworks/1.1/types.h>
#include <android/hidl/allocator/1.0/IAllocator.h>

#include <VtsHalHidlTargetTestBase.h>
#include <VtsHalHidlTargetTestEnvBase.h>
#include <gtest/gtest.h>
#include <string>

namespace android {
namespace hardware {
namespace neuralnetworks {
namespace V1_1 {
namespace vts {
namespace functional {
hidl_memory allocateSharedMemory(int64_t size);

// A class for test environment setup
class NeuralnetworksHidlEnvironment : public ::testing::VtsHalHidlTargetTestEnvBase {
    NeuralnetworksHidlEnvironment();
    NeuralnetworksHidlEnvironment(const NeuralnetworksHidlEnvironment&) = delete;
    NeuralnetworksHidlEnvironment(NeuralnetworksHidlEnvironment&&) = delete;
    NeuralnetworksHidlEnvironment& operator=(const NeuralnetworksHidlEnvironment&) = delete;
    NeuralnetworksHidlEnvironment& operator=(NeuralnetworksHidlEnvironment&&) = delete;

   public:
    ~NeuralnetworksHidlEnvironment() override;
    static NeuralnetworksHidlEnvironment* getInstance();
    void registerTestServices() override;
};

// The main test class for NEURALNETWORKS HIDL HAL.
class NeuralnetworksHidlTest : public ::testing::VtsHalHidlTargetTestBase {
   public:
    ~NeuralnetworksHidlTest() override;
    void SetUp() override;
    void TearDown() override;

    sp<V1_1::IDevice> device;
};
}  // namespace functional
}  // namespace vts

// pretty-print values for error messages

template <typename CharT, typename Traits>
::std::basic_ostream<CharT, Traits>& operator<<(::std::basic_ostream<CharT, Traits>& os,
                                                V1_0::ErrorStatus errorStatus) {
    return os << toString(errorStatus);
}

template <typename CharT, typename Traits>
::std::basic_ostream<CharT, Traits>& operator<<(::std::basic_ostream<CharT, Traits>& os,
                                                V1_0::DeviceStatus deviceStatus) {
    return os << toString(deviceStatus);
}

}  // namespace V1_1
}  // namespace neuralnetworks
}  // namespace hardware
}  // namespace android

#endif  // VTS_HAL_NEURALNETWORKS_V1_1_H
