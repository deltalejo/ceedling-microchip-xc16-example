# Ceedling Microchip XC16 Example

Sample project illustrating the setup and usage of Microchip's XC16 compiler and
Ceedling along with the [MDB plugin](https://github.com/deltalejo/ceedling-mdb-plugin)
for running tests both on simulator and target.

## Try this out

Clone:

```shell
git clone --recurse-submodules https://github.com/deltalejo/ceedling-microchip-xc16-example.git
```

Create `env.yml` file with proper paths.
e.g.:

```yaml
---
:environment:
  # MPLAB X path (for packs on MPLABX installation dir)
  - :mplabx_path: /opt/microchip/mplabx/v6.20
  # Device Packs path (for packs on user installation dir)
  - :dfp_path: ~/.mchp_packs
  # Compilers paths
  - :xc16_path: /opt/microchip/xc16/v2.10
  - :path:
      - "#{ENV['XC16_PATH']}/bin"
      - "#{ENV['PATH']}"
...
```

Run tests on simulator:

```shell
ceedling test:all
```

Run tests on target:

```shell
ceedling mdb:hwtool[<debugger>] mdb:serialport[<port>] test:all
```

E.g.:

```shell
ceedling mdb:hwtool[snap] mdb:serialport[/dev/ttyUSB0] test:all
```
