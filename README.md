# Ray Tracer

---

Following [The Ray Tracer Challenge](https://pragprog.com/book/jbtracer/the-ray-tracer-challenge).

## Dependencies

* Buck
    * https://buckbuild.com/
* Gtest
    * https://github.com/google/googletest

---

## Building Project

    $ buck build :main
    $ buck run :main
    $ buck test test/...

## The set up

    $ buck build :main
    $ buck-out/gen/
    $ buck-out/gen/main
    $ buck run :main
    $ buck test
    $ buck test test/...


## Docs

* [Gtest for Dummies](https://github.com/google/googletest/blob/master/googlemock/docs/ForDummies.md)