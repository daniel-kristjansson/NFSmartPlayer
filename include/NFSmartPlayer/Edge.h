/*
 * Copyright (c) 2017 Spotify AB.
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */
#pragma once

#include <NFGrapher/Score.generated.h>

#include <memory>
#include <string>

namespace nativeformat {
namespace smartplayer {

class Edge {
 public:
  virtual std::string source() const = 0;
  virtual std::string target() const = 0;
  virtual std::string identifier() const = 0;
  virtual std::string json() const = 0;
};

extern std::shared_ptr<Edge> createEdge(const nfgrapher::Edge &edge);
extern std::shared_ptr<Edge> createEdge(const std::string &json);

}  // namespace smartplayer
}  // namespace nativeformat
