# Benchmarks - Ray Tracer

## Environment

- Running On: MacBook Air (M2) - 8 cores (4 performance + 4 efficiency), 8 GB RAM
- macOS [version - 26.5.2], Apple clang [version - 21]

## Standard Render Workload

Final scene (about 485 spheres, materials vary), 1200x675, 100 spp, max depth: 50

## Raw Log

| Date       | Build         | Threads    | spp | Time(s)   | Notes       |
|------------|---------------|-----------:|----:|----------:|-------------|
| 2026-08-04 | Release (-O3) |          1 | 100 |  188.74   |   baseline  |
| 2026-08-05 | Release (-O0) |          1 | 100 |           |   baseline  |

## Experiments

### 1 - Compiler optimization (denominator as -O0 Running 1 thread)

| Build   | Time (s) | Speedup |
|---------|---------:|--------:|
| -O0     |          |   1.00× |
| -O3     |   188.74 |         |

### 2 - Thread scaling (denominator as -03 Release, Running 1 Thread)
