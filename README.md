# Sample-Scripts
A repo to store some sample scripts.

I am using this repo to store sample scripts, tests, config files and more; since I keep switching my linux distro.

* `thrust-samples`: While adding complex support, I wanted to test compatibility of `thrust::op` functions with complex types (`std::op` ops don't support thrust complex types).
    * `sample.cu`: contains test code to apply `thrust::acosh` on a complex tensor.
